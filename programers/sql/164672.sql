SELECT BOARD_ID,
    WRITER_ID,
    TITLE,
    PRICE,
    CASE
        WHEN STATUS = 'DONE' THEN '거래완료'
        WHEN STATUS = 'SALE' THEN '판매중'
        ELSE '예약중'
    END AS 'STATUS'
FROM USED_GOODS_BOARD
WHERE date_format(CREATED_DATE, '%Y-%m-%d') = '2022-10-05'
ORDER BY BOARD_ID DESC