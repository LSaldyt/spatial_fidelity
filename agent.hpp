struct Agent
{
    int  task;
    bool walk_style;
    bool information;

    Agent(int set_task, bool set_walk_style, bool set_information)
    {
        task        = set_task;
        walk_style  = set_walk_style;
        information = set_information;
    }
};
