n = int(raw_input())
while n:
    x=float(raw_input())
    print(x-x**3/6+x**5/120-x**7/5040+x**9/362880)
    print(1-x**2/2+x**4/24-x**6/720+x**8/40320)
    n-=1
