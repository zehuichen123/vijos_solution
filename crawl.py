import requests
from bs4 import BeautifulSoup as bs
import re
import os

headers = {
    'content-type': 'application/x-www-form-urlencoded',
    'user-agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
    'accept-language': 'zh-CN,zh;q=0.9,en;q=0.8',
    'accept-encoding': 'gzip, deflate, br',
}

class MyCrawler:
    def __init__(self, verbose=False, save_all=False):
        self.base_url = 'https://www.vijos.org'
        
        self.raw_name = input('username:')
        self.name = self.name.encode('utf8')
        self.password = input('password:')
        self.verbose = verbose
        self.save_all = save_all

        self.file_dir = 'code/'
        if not os.path.exists(self.file_dir):
            os.mkdir(self.file_dir)

        self.headers = headers
        self.data = {
            'uname': self.name,
            'password': self.password,
        }
        self.sess = requests.session()

    def login(self):
        login_url = self.base_url + '/login'
        if self.verbose:
            print('login url:', login_url)
        login_page = self.sess.post(login_url, data=self.data, headers=self.headers)
        login_bs = bs(login_page.text, 'html.parser')
        person_tag = login_bs.find_all('a', class_='nav__item')[-1]
        self.person_id = person_tag['href'].split('/')[-1]
        if self.verbose:
            print('personal UID:', self.person_id)
        self.personal_url = self.base_url + '/user/' + self.person_id
        print('login successfully!')

    def get_personal_info(self):
        if self.verbose:
            print('personal url:', self.personal_url)
        person_page = self.sess.get(self.personal_url)
        person_page_bs = bs(person_page.text, 'html.parser')
        person_zone = person_page_bs.find_all('div', class_='profile-header__main')
        rank_info = person_zone[0].find_all('p')[1].text
        self.solved_num, self.RP_value, self.rank_num = re.findall(r'\d+\.?\d*', rank_info)
        if self.verbose:
            print('%s Infomation: Solved Problem: %s, RP value: %s, Rank: %s' %\
                            (self.raw_name, self.solved_num, self.RP_value, self.rank_num))

    def parse_code(self, submit_url):
        if self.verbose:
            print('submit url:', submit_url)
        submit_page = self.sess.get(submit_url)
        submit_page_bs = bs(submit_page.text, 'html.parser')

        summary_info = submit_page_bs.find('dl', id='summary').find_all('dd')
        used_time = summary_info[1].text
        peak_memory = summary_info[2].text

        code_text = submit_page_bs.find('code').text
        return used_time, peak_memory, code_text

    def parse_problem(self, question_num):
        problem_url = self.base_url + '/p/' + str(question_num)
        if self.verbose:
            print('problem url:', problem_url)
        problem_page = self.sess.get(problem_url)
        if not problem_page.ok:
            return None
        else:
            problem_page_bs = bs(problem_page.text, 'html.parser')
            problem_name = problem_page_bs.find_all('div', class_='section__header')[0].find('h1').text
            if self.verbose:
                print('Problem %d: %s' % (question_num, problem_name))
            is_passed_tag = problem_page_bs.find_all('a', class_='record-status--text')
            if len(is_passed_tag) == 0:
                return None
            else:
                problem_status = is_passed_tag[0].text.strip(' ').strip('\n').strip(' ')
                if self.verbose:
                    print('Your status: %s'% problem_status)
                if problem_status != 'Accepted' and not self.save_all:
                    return None
                else:
                    submit_hist_href = is_passed_tag[0]['href']
                    submit_url = self.base_url + submit_hist_href
                    used_time, peak_memory, code_text = self.parse_code(submit_url)
                    submit_data = {
                        'problem_id': str(question_num),
                        'problem_name': problem_name,
                        'code': code_text,
                        'used_time': used_time,
                        'peak_memory': peak_memory,
                        'status': problem_status,
                    }
                    return submit_data

    def to_file(self, submit_data):
        if submit_data == None:
            return
        else:
            file_name = submit_data['problem_id'] + '.cpp'
            file_info = '//Problem %s: %s \n//Status: %s \n//Used Time: %s \n//Peak Memory: %s' % (submit_data['problem_id'],\
                    submit_data['problem_name'], submit_data['status'], submit_data['used_time'], submit_data['peak_memory'])
            with open(self.file_dir + file_name, 'w') as f:
                f.write(file_info + '\n')
                f.write(submit_data['code'])
            print('Saved Problem %s' % submit_data['problem_id'])