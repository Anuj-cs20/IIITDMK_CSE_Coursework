import pandas as pd

df = pd.read_csv("diabetes.csv")
l = len(df)

print("1.Probability of diabetes in given dataset given")
print("2. Age above 50")
print("3. Age between 40 and 50")
print("4. Age between 30 and 40")
print("5. Age less than 30")
print("6.For given certain conditons  ")

c_1 = 0
c_2 = 0
c_3 = 0
c_4 = 0
c_5 = 0
c_11 = 0
c_22 = 0
c_33 = 0
c_44 = 0
c_55 = 0

for i in range(0, l):
    age = int(df.loc[i, 'Age'])
    outcome = int(df.loc[i, 'Outcome'])
    if(age > 50):
        c_5 += 1
        if(outcome == 1):
            c_55 += 1
    elif(age > 40 and age < 50):
        c_4 += 1
        if(outcome == 1):
            c_44 += 1
    elif(age > 30 and age < 40):
        c_3 += 1
        if(outcome == 1):
            c_33 += 1
    elif(age < 30):
        c_2 += 1
        if(outcome == 1):
            c_22 += 1

for i in range(0, l):
    if(df.loc[i, 'Glucose'] > 120 and df.loc[i, 'BloodPressure'] > 90 and df.loc[i, 'SkinThickness'] > 30 and df.loc[i, 'Insulin'] > 150 and df.loc[i, 'BMI'] > 25):
        c_1 += 1
        if(df.loc[i, 'Outcome'] == 1):
            c_11 += 1

while 1:
    opt = input("Enter your option: ")
    if opt == '1':
        print('\nprobability of diabetes in given data set is : ',
              (c_55+c_44+c_33+c_22)/l)
    elif opt == '2':
        print("\nprobability of diabetes in given data set given age above 50 : ", c_55/c_5)
    elif opt == '3':
        print("\nprobability of diabetes in given data set given age between 40 and 50 : ", c_44/c_4)
    elif opt == '4':
        print("\nprobability of diabetes in given data set given age between 30 and 40 : ", c_33/c_3)
    elif opt == '5':
        print("\nprobability of diabetes in given data set given age less than 30 : ", c_22/c_2)
    elif opt == '6':
        print("\nprobability of diabetes with a glucose level of more than 120 + blood pressure of more than 90 + skin thickness of more than 30 + insulin above 150 + BMI above 25 : ", c_11/c_1)
    elif opt == '7':
        exit(0)
