-- info to solve the mystery
SELECT *FROM crime_scene_reports WHERE street = 'Humphrey Street';
SELECT description FROM crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28;

-- bakery scene
SELECT *FROM interviews WHERE transcript LIKE '%bakery%';

--witness one
SELECT * FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- check against licenec_plate
SELECT people.name, activity, bakery_security_logs.license_plate FROM bakery_security_logs JOIN people ON people.license_plate = bakery_security_logs.license_plate WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- check person 2 truth
SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' AND year = 2023 AND month = 7 AND day = 28;

-- name of withdraws
SELECT name FROM atm_transactions JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number JOIN people ON  bank_accounts.person_id = people.id WHERE atm_location = 'Leggett Street' AND year = 2023 AND month = 7 AND day = 28 AND transaction_type = 'withdraw';

--witness 3 phonecall
SELECT * FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

-- add name to calls
SELECT name, caller, receiver FROM phone_calls JOIN people ON phone_number = caller WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

--where are they going?
--what is the orgin number of fiftyville?
SELECT * FROM airports WHERE city = "Fiftyville";     -- its(8)

--explore airport to find the destination city.
SELECT origin_airport_id, destination_airport_id FROM flights JOIN airports ON origin_airport_id = airports.id WHERE origin_airport_id = 8 AND  year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;

--we have full_name on airport table and by adding orgin and destination back of it we determin wt name we looking for in ariports
SELECT origin.full_name as origin_airport, destination.full_name as destination_airport FROM flights JOIN airports origin ON origin_airport_id = origin.id JOIN airports destination ON destination_airport_id = destination.id WHERE origin.id = 8 AND  year = 2023 AND month = 7 AND day = 29 ORDER BY hour, minute;

-- combine info from 3 witnesses
SELECT people.name FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE bakery_security_logs.year = 2023 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute BETWEEN 15 AND 25
AND atm_location = 'Leggett Street' AND atm_transactions.year = 2023 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND transaction_type = 'withdraw'
AND phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28 AND duration < 60;

-- last determination by looking at passanger lists
SElECT name FROM people JOIN passengers ON passengers.passport_number = people.passport_number WHERE flight_id = 36;

--THE COMPLICE
--im joining ppl 2 times once for the caller then for the receiver and then determine the caller it bruce then who receiverd the call and add caller and recever after eacg timr called people as a name so computer knows.
SELECT receiver.name as receiver FROM phone_calls JOIN people caller ON caller = caller.phone_number JOIN people receiver ON receiver = receiver.phone_number WHERE caller.name = 'Bruce' AND phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28 AND duration < 60;
