type UserGreetingProps = {
    Data: {
        IsloggedIn:boolean;
        UserName: string
    }
};

export default function UserGreeting ({Data}: UserGreetingProps) {
    if(Data.IsloggedIn) {
        return <h2>Welcome {Data.UserName}</h2>;
    } else {
        return <h2>Bad News</h2>;
    }
}
