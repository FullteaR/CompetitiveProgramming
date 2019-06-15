while True:
    try:
        strings=input()

        for i in range(26):
            _strings=""
            for s in strings:
                if ord('a')<=ord(s) and ord(s)<=ord('z'):
                    _strings+=chr((ord(s)-ord('a')+1)%26+ord('a'))
                else:
                    _strings+=s
            strings=_strings
            if "the" in strings or "this" in strings or "that" in strings:
                print(strings)
                break
    except EOFError:
        break
