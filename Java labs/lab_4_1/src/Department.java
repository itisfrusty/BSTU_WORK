import java.util.HashSet;
import java.util.Set;
public  class Department implements Unit{
	private String name;
	private Set<Employee> employees = new HashSet<>();
	public Department(String n){
		name = n;
	}
	public void setName(String newName){
		name = newName;
	}
	public String getName(){
		return name;
	}
	public void  addEmployee(Employee newEmployee){
		employees.add(newEmployee);
		// связываем сотрудника с этим отделом
		newEmployee.setDepartment(this); 
	}
	public Set<Employee>  getEmployees(){
		return employees;
	}
	public void  removeEmployee(Employee e){
		employees.remove(e);
	}
	@Override
	public int getPersonCount(){
		return getEmployees().size();
	}
}
