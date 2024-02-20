import './Student.css'

type Props = {
    Name: string;
    Age: number;
    IsStudent: boolean
};

const Student: React.FC<Props> = ({Name,Age,IsStudent}) => {
    return(
    <div className = "Student">
        <p className = "StudentName">
            Name: {Name}
        </p>
        <p className = "StudentAge">
            Age: {Age}  
        </p>
        <p className = "StudentFlag">
            Is student: {IsStudent ? "Yes" : "No"}  
        </p>
    </div>
    );
}

Student.defaultProps = {
    Name: "Guest",
    Age: 0,
    IsStudent: false
}

export default Student

  