numeros = input().split()

res1 = max(numeros[0], numeros[2])
res2 = min(numeros[1], numeros[3])

if res1 <= res2:
    print(f"[{res1},{res2}]")
else:
    print("[]")