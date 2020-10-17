def binary_search(l, num_find):
    start = 0
    end = len(l) - 1
    mid = (start + end) // 2
    
    found = False
    position = -1

    while start <= end:
        if l[mid] == num_find:
            found = True
            position = mid
            break
        
        if num_find > l[mid]:
            start = mid + 1
            mid = (start + end) // 2
        else:
            end = mid - 1
            mid = (start + end) // 2

    return (found, position)

if __name__=='__main__':
    l = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    num = input("Enter a number:")
    num=int(num)
    found = binary_search(l, num)
    if found[0]:
        print('Number %d found at position %d'%(num, found[1]+1))
    else:
        print('Number %d not found'%num)