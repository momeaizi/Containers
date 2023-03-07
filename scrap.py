from bs4 import BeautifulSoup
import requests
from functions import vector


file = open("taha.cpp", "w")

file.write("#include <iostream>\n#include <iomanip>\n#include <vector>\n#include \"vector/vector.hpp\"\nint	main()\n{\n")
for func in vector:
    url = f'https://cplusplus.com/reference/vector/vector/{func}/'
    response = requests.get(url)

    file.write(f"std::cout << \"[[\" << std::setw(40) << \"{func}\t\t\t]]\" << std::endl;\n")

    soup = BeautifulSoup(response.text, 'html.parser')

    codes = soup.find_all(class_='source')

    code = codes[-1]

    func_test = code.text.replace("#include <iostream>\n#include <vector>\n\nint main ()", "")
    func_test = func_test.replace("#include <iostream>\n#include <vector>\n\nmain ()", "")
    func_test = func_test.replace("for (int i", "for (size_t i")
    func_test = func_test.replace("return 0;\n", "")
    
    file.write(func_test)
    file.write("\n")


file.write("}\n")
file.close()
