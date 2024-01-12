# Avtonomera 🚨
> All data was taken from [Wikipedia](https://en.wikipedia.org/wiki/Vehicle_registration_plates_of_Russia).

This program identifies the region of a **Russian license plate** by it's **registration region code**.

![nomera](./img/png/nomera_2.png)

## How does it work
The program performs a *dichotomous search* (fastest searching algorithm) through Wikipedia's data, which has been adapted for it by myself. Once the registration region code is found, shows the region associated with it.

![Registration Codes Map](./img/png/registration_codes_map.png)

## Usage Example
Let's try the program on a real car, like for example this beautiful **Mercedes-Benz S63 AMG**.

![S63 AMG](./img/demo/S63_AMG.jpg)
> Picture by [@avtonomer44rus](https://www.instagram.com/avtonomer44rus/)

The first step is to identify the **registration region code**. We can see it pretty clearly with the example we saw earlier.

![Plate](./img/demo/plate_44_marked.png)

As we can see, the registration region code is `44`. Let's try it on the program now.

![Demo](./img/demo/demo_program.png)

After entering the file name of the Wikipedia data (stored @ `./data/avtonomera.txt`), the program found the region of the code we were looking for.

The code `44` ended to be from **Kostroma** (Кострома).

![Kostroma](./img/demo/Kostroma.jpg)

> *Thanks for reading)*