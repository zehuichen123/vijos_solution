from crawl import MyCrawler
import time

def main():
    lovesnowbest_crawler = MyCrawler(verbose=False, save_all=True)
    lovesnowbest_crawler.login()
    lovesnowbest_crawler.get_personal_info()
    for i in range(1000, 2050):
        data = lovesnowbest_crawler.parse_problem(i)
        lovesnowbest_crawler.to_file(data)
        time.sleep(1)

if __name__ == '__main__':
    main()