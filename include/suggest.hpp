// Copyright 2021 <geraldy12319@gamil.com>

#ifndef INCLUDE_SUGGEST_HPP_
#define INCLUDE_SUGGEST_HPP_

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

// Класс отвечает за хранение json файла на сервере, файл может изменяться
// поэтому есть возможность упрощенной работы с ним, загрузки из него данных
class Json_storage {
 public:
  explicit Json_storage(const std::string& filename);
  // возвращает данные из хранилища
  json get_storage() const;
  // загружает данные из файла в хранилище
  void Load();

 private:
  std::string filename_;
  json storage_;
};

// Класс отвечает за текущую коллекцию предположений
class Suggestions_collection {
 public:
  Suggestions_collection();
  void Update(json storage);
  json Suggest(const std::string& input);

 private:
  json suggestions_;
};

#endif  // INCLUDE_SUGGEST_HPP_
