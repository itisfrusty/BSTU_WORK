import java.util.HashSet;
import java.util.Set;

// наследуем класс Man
	public  class Employee extends Man{
		private String position;
		private IdCard iCard;
		private Set<Room> room = new HashSet<>();
		private Department department;
		private Set<PastPosition> pastPosition = new HashSet<>();
		// создаем и конструктор
		public  Employee(String cName, String cSurname, String cPosition){
			name = cName;
			surname = cSurname;
			position = cPosition;
		}
		public void setPosition(String newPosition){				
				// сначала должность заносим в список прежних должностей
				PastPosition pastPosition = new PastPosition(this.getPosition(), this.getDepartment());				
				this.setPastPosition(pastPosition);
				// меняем должность
				position = newPosition;
		}
		public String getPosition(){
				return position;
		}
		public void setIdCard(IdCard c){
			iCard = c;
		}
		public IdCard getIdCard(){
			return iCard;
		}
		public void setRoom(Room newRoom){
			room.add(newRoom);
		}
		public Set<Room>  getRoom(){
			return room;
		}
		
		public void  deleteRoom(Room r){
			room.remove(r);
		}
		
		public void setDepartment(Department d){
			department = d;
		}
		
		public Department getDepartment(){
			return department;
		}
		
		public void setPastPosition(PastPosition p){
			pastPosition.add(p);
		}
		
		public Set<PastPosition>  getPastPosition(){
			return pastPosition;
		}
		
		public void deletePastPosition(PastPosition p){
			pastPosition.remove(p);
		}
	}
