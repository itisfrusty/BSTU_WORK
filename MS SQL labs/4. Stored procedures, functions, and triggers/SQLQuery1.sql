INSERT INTO dbo.Teacher
Values (
'6',
'Germin Fedor Pavlovich',
'Informatika',
'4'
)
UPDATE dbo.Teacher
SET Specialnost = 'Literatura'
Where Stazh = '9'
DELETE FROM dbo.Teacher
Where Specialnost = 'Fizika'
