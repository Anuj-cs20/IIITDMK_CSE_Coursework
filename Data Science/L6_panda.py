import pandas as pd

data = {"Name": ["Ram", "Sam", "Prabhu"],
        "Account Number": ["9893893891", "9893893898", "9893893871"],
        "Account Type": ["SB", "CA", "SB"],
        "Adhaar_No": ["95938938173", "95938938179", "95938938159"],
        "Balance": ["8989839", "7690990", "989330"]}

data1 = {"Name": ["Ram", "Sam", "Prabhu"],
         "Adhaar_No": ["95938938173", "95938938179", "95938938159"],
         "Contact No.": ["9840787333", "9840787343", "9840787353"],
         "Dob": ['12-2-1990', '12-2-2000', '12-2-2010'],
         "Address": ['No 23 ,kandigai,chennai 127', 'No 73 ,Melakottaiyuru ,chennai 127', 'No 43 ,Anna Nagar,chennai 127']}

df = pd.DataFrame(data)
df.to_csv('cs20b1100_SBIAccountHolder.csv', index=False, sep='\t')

df1 = pd.DataFrame(data1)
df1.to_csv('cs20b1100_Aadhar.csv', index=False, sep='\t')

print("================ Menu ==================")
print("1. Add an Account Holder Details")
print("2. Delete an Account Holder Details")
print("3. Credit")
print("4. Debit")
print("5. Print Account Details")
print("6. Merge & Exit")
while 1:
    opt = int(input("Enter your option: "))
    if opt == 1:
        df.loc[len(df.index)] = ['Anuj', "9893893801",
                                 "SB", "95938938101", "1000000"]
        df.loc[len(df.index)] = ['Chow', "9893893802",
                                 "CA", "95938938102", "9999999"]
        df.to_csv('cs20b1100_SBIAccountHolder.csv', index=False, sep='\t')
        print(df)
    elif opt == 2:
        df = df.drop([0])
        df.to_csv('cs20b1100_SBIAccountHolder.csv', index=False, sep='\t')
        print(df)
    elif opt == 3:
        accNo = input("Enter Account Number: ")
        amo = int(input("Enter Amount: "))
        df.loc[df['Account Number'] == accNo, 'Balance'] = str(
            int(df.loc[df['Account Number'] == accNo, 'Balance']) + amo)
        df_acc = df[df['Account Number'] == accNo]
        df.to_csv('cs20b1100_SBIAccountHolder.csv', index=False, sep='\t')
        print(df_acc)
    elif opt == 4:
        accNo = input("Enter Account Number: ")
        amo = int(input("Enter Amount: "))
        if int(df.loc[df['Account Number'] == accNo, 'Balance']) > amo:
            df.loc[df['Account Number'] == accNo, 'Balance'] = str(
                int(df.loc[df['Account Number'] == accNo, 'Balance']) - amo)
            df_acc = df[df['Account Number'] == accNo]
            df.to_csv('cs20b1100_SBIAccountHolder.csv', index=False, sep='\t')
            print(df_acc)
        else:
            print("insufficient balance")
    elif opt == 5:
        accNo = input("Enter Account Number: ")
        df_acc = df[df['Account Number'] == accNo]
        print(df_acc)
    elif opt == 6:
        df3 = pd.merge(df, df1, on='Name', how='left')
        df3.to_csv('cs20b1100_Merge.csv', index=False, sep='\t')
        print(df3)
        print("Exited")
        break
