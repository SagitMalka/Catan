// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
// #include "Controler/Game.hpp"
// TEST_CASE("Game initialization and setup") {
//    Game game;

//     SUBCASE("Add players and retrieve them") {
//         std::string name;
//         name = "Sagit";
//         game.addPlayer(name, 1);
//         name.clear();
//         name = "Kfir";
//         game.addPlayer(name, 2);
//         name.clear();
//         name = "Mimi";
//         game.addPlayer(name, 3);


//         const auto& players = game.getPlayers();
//         CHECK(players.size() == 3);
//         CHECK(players[0]->getName() == "Sagit");
//         CHECK(players[1]->getId() == 2);
//         CHECK(players[2]->getId() == 3);

//     }

//     SUBCASE("Initial game state") {
//         CHECK(game.isGameOver() == false);
//         CHECK(game.isInitialPlacementPhase() == true);
//         CHECK(game.getWinner() == nullptr);
//     }
// }

// TEST_CASE("Game actions") {
//     Game game;
//     game.addPlayer("Sagit", 1);

//     SUBCASE("Roll dice") {
//         game.rollDice("Sagit");
//         // Add assertions based on expected behavior after rolling dice
//     }

//     SUBCASE("Build settlement") {
//         // Assuming nodeId and playerId are valid for your game setup
//         int nodeId = 1;
//         int playerId = 1;
//         // Add assertions based on expected behavior after building settlement
//     }

//     SUBCASE("Build road") {
//         // Assuming roadId and playerId are valid for your game setup
//         int roadId = 1;
//         game.availableRoadsToBuild();
//         // Add assertions based on expected behavior after building road
//     }

// //    auto player = game.getPlayers()[0];
// }

// TEST_CASE("Game state changes") {
//     Game game;
//     auto player1 = std::make_shared<Player>("Sagit", 1);
//     auto player2 = std::make_shared<Player>("Kfir", 2);
//     game.addPlayer(player1);
//     game.addPlayer(player2);

//     SUBCASE("Start and end turns") {
//         game.startTurn();
//         CHECK(game.getCurrentPlayer() == player1);

//         game.endTurn();
//         CHECK(game.getCurrentPlayer() == player2);
//     }

//     SUBCASE("End of initial placement phase") {
//         game.endOfInitialPlacement();
//         CHECK(game.isInitialPlacementPhase() == false);
//     }
// }

