#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

TaskStatus Next (TaskStatus status)
{
  return static_cast<TaskStatus>(static_cast<int>(status) + 1);
}

void RemoveZeros(TasksInfo& task_info)
{
  std::vector<TaskStatus> status_to_remove;
  for (const auto& task_item : task_info)
  {
    if (task_item.second == 0)
    {
      status_to_remove.push_back(task_item.first);
    }
  }

  for (const TaskStatus status : status_to_remove)
  {
    task_info.erase(status);
  }
}

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const std::string& person) const;
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const std::string& person);
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const std::string& person, int task_count);
private:
  std::map<string, TasksInfo> person_tasks_;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person) const
{
  return person_tasks_.at(person);
}

void TeamTasks::AddNewTask(const std::string& person)
{
  ++person_tasks_[person][TaskStatus::NEW];
}

std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const std::string& person, int task_count)
{
  TasksInfo updated_tasks, untouched_tasks;
  TasksInfo& tasks = person_tasks_[person];

  for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status))
  {
    updated_tasks[Next(status)] = min(tasks[status], task_count);
    task_count -= updated_tasks[Next(status)];
  }

  for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status))
  {
    untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
    tasks[status] = updated_tasks[status] + untouched_tasks[status];
  }

  tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

  RemoveZeros(tasks);
  RemoveZeros(untouched_tasks);
  RemoveZeros(updated_tasks);

  return {updated_tasks, untouched_tasks};
}


