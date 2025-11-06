# Real Estate Company

## 📌 Business Case
A real estate company invests in three types of properties:  
1. Apartments  
2. Townhouses  
3. Semi-detached houses  

The company buys these properties and rents them out. Management requires a program that calculates and reports the financial performance of each property type.

---

## 📋 Requirements
For each property type, the program must calculate and display:
- **Monthly earnings**
- **Return on investment (ROI)**
- **Estimated current value**
- **Capital gains**

---

## 🏗️ Design

### Real Estate Company
- Attributes: company name, address, 5 apartments, 5 townhouses, 5 semi-detached houses.  
- Performance metrics are calculated by summing the values across all properties of each type.

### Apartments
- Attributes: address, rooms, bathrooms, purchase price, monthly rent, condo fees, monthly earnings, ROI, current value, capital gains.  
- Formulas:  
  - `monthly earnings = monthly rent – monthly condo fees`  
  - `ROI = (100 × 12 × monthly earnings) / purchase price`  
  - `current value = (12 × monthly earnings) / 0.05`  
  - `capital gains = current value – purchase price`

### Townhouses
- Attributes: address, rooms, bathrooms, purchase price, monthly rent, utilities, condo fees, property tax, monthly earnings, ROI, current value, capital gains.  
- Formulas:  
  - `monthly earnings = monthly rent – utilities – condo fees – property tax`  
  - ROI, current value, and capital gains follow the same formulas as apartments.

### Semi-Detached Houses
- Attributes: address, rooms, bathrooms, purchase price, monthly rent, utilities, property tax, monthly earnings, ROI, current value, capital gains.  
- Formulas:  
  - `monthly earnings = monthly rent – utilities – property tax`  
  - ROI, current value, and capital gains follow the same formulas as apartments.

---

## ⚙️ Implementation
- **Structures:**  
  - `struct RealEstateCompany`  
  - `struct Apartment`  
  - `struct Townhouse`  
  - `struct SemiDetachedHouse`  
  - `struct Property`  

- **Functions:**  
  - Each structure has associated functions to calculate performance metrics.  
  - Parameters are chosen carefully as pass-by-value or pass-by-address depending on efficiency and intent.

- **Main Program:**  
  - Provided in `RealEstateMain.c`  
  - Reads data from `Apartments.txt`, `Townhouses.txt`, and `SemiDetachedHouses.txt`  
  - Replace magic numbers with constants.  
  - Copy extracted data into the appropriate structures.

---

## 🧪 Testing & Expected Output
A correctly running program should produce output similar to:

```
The following are financial stats for Brookfield Asset Management, 11 Yonge Street.

For the apartments, the monthly earnings are $11750.00, the roi is 12.05%,
the total value is $2820000.00 and the capital gains are $1650000.00

For the townhouses, the monthly earnings are $15160.00, the roi is 8.23%,
the total value is $3638400.00 and the capital gains are $1428400.00

For the semidetached houses, the monthly earnings are $18040.00, the roi is 6.76%,
the total value is $4329600.00 and the capital gains are $1129600.00
```
