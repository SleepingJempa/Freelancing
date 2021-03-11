def show_menu_items():
    print('0. Exit the program')
    print('1. Rang ha')
    print('2. Mive ha')
    print('3. Information')

    number = input()

    if number == '1':
        rang = []
        print('Rang hara type konid va sepas Enter ra bezanid')
        rang = list(map(str, input().split()))
        print(rang)
        return

    if number == '2':
        mive = ()
        print('Mive hara type konid va sepas Enter ra bezanid')
        mive = tuple(map(str, input().split()))
        print(mive)
        return

    if number == '3':
        info = []
        print('Daneshjoo:')


        name = ['Naam?', input('Naam?\n')]
        family = ['Naame khanevadegi?', input('Naame khanevadegi?\n')]
        code = ['Kod medi?', input('Kod medi?\n')]
        tavalod = ['Tarikhe tavalod?', input('Tarikhe tavalod?\n')]
        phone = ['Shomare tamas?', input('Shomare tamas?\n')]

        info = [
            name,
            family,
            code,
            tavalod,
            phone
        ]

        print(info)
        return

    if number == '0':
        print('Terminated the app')
        exit()
        return
    
    print('Shomare eshtbah ast.')
    return show_menu_items()

show_menu_items()