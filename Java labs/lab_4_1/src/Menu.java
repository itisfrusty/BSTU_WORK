public  class Menu{
	public  void showEmployees(Employee[] employees){

		System.out.println("Список сотрудников:");
		for (Employee employee : employees) {
			if (employee instanceof Employee) {
				System.out.println(employee.getName() + " - " + employee.getPosition());
			}
		}
	}
}
