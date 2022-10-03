import threading
import random
import time

from typing import List, Type, TypeVar


class Account:

    def __init__(self, balance: int = 0):
        self.balance = balance


    def transfer(self, account, amount: int):
        if self.balance < amount:
            return

        if not isinstance(account, Account):
            return

        self.balance -= amount
        time.sleep(0.001)
        account.balance += amount



def two_random_accounts(accounts):
    account_1 = random.choice(accounts)
    account_2 = random.choice(accounts)

    while account_1 == account_2:
        account_2 = random.choice(accounts)

    return account_1, account_2



def check_total_money_in_bank(accounts: List[Account], amount: int):
    current_amount = sum(account.balance for account in accounts)

    if current_amount != amount:
        print(f"Error! Inconsistent bank balance! Current [{current_amount:.2f}€] total [{amount:.2f}€]",flush=True)
    else:
        print(f"Consistent bank balance! Current [{current_amount:.2f}€] total [{amount:.2f}€]",flush=True)



def services(accounts, amount):
    for _ in range(1, 1000):
        account_1, account_2 = two_random_accounts(accounts)
        account_1.transfer(account_2, random.randint(1, 100))
        check_total_money_in_bank(accounts, amount)

        

def main():
    accounts = [
        Account(balance=random.randint(5_000, 10_000)),
        Account(balance=random.randint(5_000, 10_000)),
        Account(balance=random.randint(5_000, 10_000)),
        Account(balance=random.randint(5_000, 10_000)),
        Account(balance=random.randint(5_000, 10_000)),
        Account(balance=random.randint(5_000, 10_000)),
        Account(balance=random.randint(5_000, 10_000))
    ]
    
    amount = sum(account.balance for account in accounts)

    print("Start of financial transactions...")

    tasks = [
        threading.Thread(target=services, args=[accounts, amount]),
        threading.Thread(target=services, args=[accounts, amount]),
        threading.Thread(target=services, args=[accounts, amount]),
        threading.Thread(target=services, args=[accounts, amount])
    ]

    [task.start() for task in tasks]
    [task.join() for task in tasks]

    print("Completed transactions!")
    
    check_total_money_in_bank(accounts, amount)



if __name__ == '__main__':
    main()