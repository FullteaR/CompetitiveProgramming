def wrought(cost_dict, ingredients_dict):
    items = list(cost_dict.keys())
    n=len(items)
    for _ in range(n):
        for item in items:
            if item in ingredients_dict:
                ingredients = ingredients_dict[item]
                cost = 0
                for ingredient in ingredients:
                    cost+=cost_dict[ingredient]
                cost_dict[item]=min(cost, cost_dict[item])


    return cost_dict


while True:
    n = int(input())
    if n == 0:
        break

    cost_dict = {}
    for _ in range(n):
        item, price = input().split(" ")
        cost_dict[item] = int(price)

    ingredients_dict = {}
    m = int(input())
    for _ in range(m):
        okq = input().split(" ")
        ingredients_dict[okq[0]] = okq[2::]

    target = input()
    print(wrought(cost_dict, ingredients_dict)[target])
