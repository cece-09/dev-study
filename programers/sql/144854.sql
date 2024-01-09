SELECT b.BOOK_ID,
    a.AUTHOR_NAME,
    date_format(b.PUBLISHED_DATE, "%Y-%m-%d") AS PUBLISHED_DATE
FROM BOOK AS b
    JOIN AUTHOR AS a ON b.AUTHOR_ID = a.AUTHOR_ID
WHERE b.CATEGORY = "경제"
ORDER BY PUBLISHED_DATE ASC