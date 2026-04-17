SELECT 
    p.product_id,
    ROUND(
        IFNULL(SUM(p.price * un.units) / NULLIF(SUM(un.units), 0), 0),
        2
    ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold un
    ON p.product_id = un.product_id
    AND un.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;