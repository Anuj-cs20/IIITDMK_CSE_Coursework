import numpy as np

print("1. Matrix Addition")
print("2. Matrix Subtraction")
print("3. Scalar Matrix Multiplication")
print("4. Elementwise Matrix Multiplication")
print("5. Matrix Multiplication")
print("6. Matrix Transpose")
print("7. Trace of a Matrix")
print("8. Solve System of Linear Equations")
print("9. Determinant")
print("10. Inverse")
print("11. Singular Value Decomposition")
print("12. Eigen Value")
print("13. Search an Element")
print("14. Sum of Difference of Upper and Lower Triangular Matrix")
print("15. Exit")

M = int(input("Enter number of Rows: "))
N = int(input("Enter number of Columns: "))

l1 = []
print("Enter elements of matrix A: ")
for i in range(M*N):
    e = int(input())
    l1.append(e)

A = np.array(l1).reshape(M, N)
print(A)

l2 = []
print("Enter elements of matrix B: ")
for i in range(M*N):
    e = int(input())
    l2.append(e)

B = np.array(l2).reshape(M, N)

print(B)

while 1:
    opt = int(input("\nEnter an option: "))
    if opt == 1:
        print(f"A + B =\n{A + B}")
    elif opt == 2:
        print(f"A - B =\n{A - B}")
        print(f"\nB - A =\n{B - A}")
    elif opt == 3:
        k = int(input("Enter a number: "))
        print(f"k . A =\n{k * A}")
        print(f"\nk . B =\n{k * B}")
    elif opt == 4:
        print(f"A . B =\n{A * B}")
    elif opt == 5:
        l3 = []
        print("Enter elements of matrix C: ")
        for i in range(M*N):
            e = int(input())
            l3.append(e)

        C = np.array(l3).reshape(N, M)
        print(f"A x C =\n{A @ C}")
        print(f"\nB x C =\n{B @ C}")
    elif opt == 6:
        print(f"A_T =\n{A.transpose()}")
        print(f"\nB_T =\n{B.transpose()}")
    elif opt == 7:
        print(f"Trace A = {np.trace(A)}")
        print(f"Trace B = {np.trace(B)}")
    elif opt == 8:
        l4 = []
        print("Enter elements of matrix D: ")
        for i in range(M):
            e = int(input())
            l4.append(e)

        D = np.array(l4).reshape(M, 1)
        print(f"Linear eq. sol of A = {np.linalg.solve(A,D)}")
        print(f"Linear eq. sol of B = {np.linalg.solve(B,D)}")
    elif opt == 9:
        print(f"|A| = {np.linalg.det(A)}")
        print(f"|B| = {np.linalg.det(B)}")
    elif opt == 10:
        print(f"Inverse of A =\n{np.linalg.inv(A)}")
        print(f"\nInverse of B =\n{np.linalg.inv(B)}")
    elif opt == 11:
        print(f"SVD of A =\n{np.linalg.svd(A)}")
        print(f"\nSVD of B =\n{np.linalg.svd(B)}")
    elif opt == 12:
        print(f"Eigen Value of A =\n{np.linalg.eig(A)}")
        print(f"\nEigen Value of B =\n{np.linalg.eig(B)}")
    elif opt == 13:
        x = int(input("Enter a Number to search in matrix A: "))
        print(f"Eigen Value of A =\n{np.where(A == x)}")
    elif opt == 14:
        print("Difference b/w Upper and Lower Triangular Matrix")
        print(f"in Matrix A =\n{np.triu(A) - np.tril(A)}")
    elif opt == 15:
        print("Exited.")
        break
    else:
        print("\n!!!! Enter a proper option !!!!")
