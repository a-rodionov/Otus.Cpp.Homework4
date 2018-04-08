#pragma once

/*!
  \file version.h
  \brief Объявление типа и функций работы с версией ПО.
*/

#include "version_numbers.h"
#include <iostream>

/*!
  Тип, описывающий версию ПО в виде трех целочисленных чисел.
*/
struct version_info{

  /*!
    \brief Конструктор по умолчанию. Инициализирует значения версий нулями.
  */
  version_info()
    { version_info(0, 0, 0); }

  /*!
    \brief Конструктор, инициализирующий значения версий входными значениями.
    \param[in] major major часть версии.
    \param[in] minor minor часть версии.
    \param[in] patch patch часть версии.
  */
  version_info(const int major,
               const int minor,
               const int patch)
    : _major(major), _minor(minor), _patch(patch) {}

  int _major;
  int _minor;
  int _patch;
};

bool operator==(const version_info& lhs, const version_info& rhs);
bool operator!=(const version_info& lhs, const version_info& rhs);
bool operator<(const version_info& lhs, const version_info& rhs);
bool operator>(const version_info& lhs, const version_info& rhs);
bool operator<=(const version_info& lhs, const version_info& rhs);
bool operator>=(const version_info& lhs, const version_info& rhs);

/*!
  \brief Перегреженный оператор вывода типа version_info в поток.
  \param[in,out] out Поток вывода.
  \param[in] out_version Объект версии ПО.
  \return Поток вывода.
*/
std::ostream& operator<<(std::ostream& out, const version_info& out_version);

/*!
  \brief Получение текущей версии ПО. Значения версий инициализируются
  константами из файла version_numbers.h: PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR,
  PROJECT_VERSION_PATCH.
  \return Объект типа version_info с текущей версией ПО.
*/
version_info version();
