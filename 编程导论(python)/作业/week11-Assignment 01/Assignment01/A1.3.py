import decimal

decimal.getcontext().prec = 1000
print(decimal.Decimal(7)/decimal.Decimal(911))
