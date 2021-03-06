// Copyright (c) 2018, The Bitcoin Nova Developers
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <zedwallet/ColouredMsg.h>
#include <zedwallet/Types.h>

enum Action {Open, Generate, Import, SeedImport, ViewWallet};

Action getAction(Config &config);

void welcomeMsg();

void run(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node,
         Config &config);

void inputLoop(std::shared_ptr<WalletInfo> &walletInfo,
               CryptoNote::INode &node);

bool shutdown(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node,
              bool &alreadyShuttingDown);

std::string getInputAndDoWorkWhileIdle(std::shared_ptr<WalletInfo> &walletInfo);

std::string getCommand(std::shared_ptr<WalletInfo> &walletInfo);

Maybe<std::shared_ptr<WalletInfo>> handleAction(CryptoNote::WalletGreen &wallet,
                                                Action action, Config &config);
