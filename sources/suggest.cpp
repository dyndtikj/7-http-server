// Copyright 2021 <geraldy12319@gamil.com>

#include <suggest.hpp>
#include <exception>
#include <fstream>
#include <iostream>
#include <algorithm>

Json_storage::Json_storage(const std::string& filename) : filename_(filename) {}
json Json_storage::get_storage() const { return storage_; }
void Json_storage::Load() {
  try {
    std::ifstream in(filename_);
    in >> storage_;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

Suggestions_collection::Suggestions_collection() { suggestions_ = {}; }

void Suggestions_collection::Update(json storage) {
  std::sort(storage.begin(), storage.end(),
            [](const json& a, const json& b) -> bool {
              return a.at("cost") > b.at("cost");
            });
  suggestions_ = storage;
}

json Suggestions_collection::Suggest(const std::string& input) {
  json result;
  for (size_t i = 0, m = 0; i < suggestions_.size(); ++i) {
    if (input == suggestions_[i].at("id")) {
      json tmp;
      tmp["text"] = suggestions_[i].at("name");
      tmp["position"] = m++;
      result["suggestions"].push_back(tmp);
    }
  }
  return result;
}
