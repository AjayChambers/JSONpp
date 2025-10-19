/**
 * ***************************************************************
 * FILENAME:  'diagnostics.hpp'
 * DIRECTORY: 'include'
 * PROJECT:   'JSON++ (or JSONpp)'
 *
 * DESCRIPTION: 'diagnostics.hpp' contains the declarations for
 * Json namespace members defined in diagnostics.cpp. The purpose
 * of the 2 named files is to proved JSON++ project with a way to
 * communicate with users on the client side: The users using the
 * software that implements JSON++ (i.e. CLI, lib, extension, etc)
 *
 * ---------------------------------------------------------------
 *
 * COPYRIGHT (C) 2025 Andrew J Chambers Jr
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * ************************************************************* */

#pragma once

#ifndef DIAGNOSTIC_HPP
#define DIAGNOSTIC_HPP

#include <json/token.hpp>

#include <set>
#include <string>
#include <text-coords.hpp>

namespace Json {

enum class ErrorType { UNEXPECTED = 1, NOT_FOUND = 2, INVALID = 3 };


std::string toString(const ErrorType &id);

class DiagnosticReport {
   private:
    ErrorType   id_;
    std::string cause_  = "";
    std::string report_ = "";


   public:
    DiagnosticReport(ErrorType id, std::string cause = "");

    ErrorType   id() const noexcept;
    std::string report() const noexcept;
    std::string cause() const noexcept;


   protected:
    virtual void formatReport();
    void         setReport(std::string report) noexcept;
};



/// @brief T.D.R. = "Token Diagnostic Report"
class TDR : public DiagnosticReport {
   private:
    Token       token;
    TextCoords  location;
    TokenType   tokenType;
    std::string tokenValue;

   public:
    TDR(ErrorType id, Token token, std::string cause = "");

   protected:
    void formatReport() override;
};

}

#endif