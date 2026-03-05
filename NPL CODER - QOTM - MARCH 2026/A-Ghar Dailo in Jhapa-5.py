def solve():
    n , k = map(int, input().split())

    if k < 2:
        print(*(0 for _ in range(n)))
        return

    divs = [[] for _ in range(k + 1)]
    for i in range(2, k + 1):
        for j in range(i, k + 1, i):
            divs[j].append(i)

    neutral_count = [len(divs[i]) for i in range(k + 1)]
    is_neutral = [True] * (k + 1)
    
    ans = [0] * n
    
    for day in range(60):
        best_house = -1
        max_gain = -1
        
        
        for h in range(2, k + 1):
            if is_neutral[h]:
                if neutral_count[h] > max_gain:
                    max_gain = neutral_count[h]
                    best_house = h
        
        if best_house == -1 or max_gain == 0:
            break
            
        convinced_count = 0
        for d in divs[best_house]:
            if is_neutral[d]:
                is_neutral[d] = False
                convinced_count += 1
                
                for multiple in range(d, k + 1, d):
                    neutral_count[multiple] -= 1
        
        ans[day % n] += convinced_count

    print(*(ans))

if __name__ == "__main__":
    solve()