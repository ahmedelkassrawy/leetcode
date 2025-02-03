# Write your MySQL query statement below

SELECT
    r.contest_id,
    ROUND((COUNT(r.user_id) * 100.0 / (SELECT COUNT(user_id) FROM users)), 2) AS percentage
FROM register r
JOIN users u
ON r.user_id = u.user_id
GROUP By r.contest_id
ORDER BY 
    percentage DESC,
    r.contest_id ASC;