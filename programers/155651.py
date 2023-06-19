def solution(book_time):
    answer = 0
    rooms = []

    # integer 변환
    for time in book_time:
        for i in range(2):
            h, m = map(int, time[i].split(":"))
            time[i] = h * 60 + m

    # sort
    book_time.sort(key=lambda b: b[0])

    rooms.append(book_time[0][1] + 10)

    for i in range(1, len(book_time)):
        isFound = False
        for j in range(len(rooms)):
            if (book_time[i][0] >= rooms[j]):  # 들어갈 수 있음
                rooms[j] = book_time[i][1] + 10
                isFound = True
                break
        if (isFound == False):
            rooms.append(book_time[i][1] + 10)

    answer = len(rooms)
    return answer
