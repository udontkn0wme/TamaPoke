#pragma once
#include <stdint.h>

// GENERADO por tools/gen_dex.py desde tools/dex_data.py - no editar

#define DEX_COUNT 809
#define DEX_EEVEE 133
// EEVEE's branches. DexEntry holds ONE evolvesTo (134), so the other
// seven cannot live in the table. Generated from EEVEE_BRANCHES in
// dex_data.py, which is also what marks all eight evolution-only.
#define EEVEE_EVO_COUNT 8
static const int16_t EEVEE_EVOS[EEVEE_EVO_COUNT] = { 134, 135, 136, 196, 197, 470, 471, 700 };

// The 18 current types. See tools/dex_types.py for why this game uses the
// modern chart rather than the Gen 1 one.
enum PkType : uint8_t {
  T_NORMAL, T_FIRE, T_WATER, T_ELECTRIC, T_GRASS, T_ICE, T_FIGHTING, T_POISON, T_GROUND, T_FLYING, T_PSYCHIC, T_BUG, T_ROCK, T_GHOST, T_DRAGON, T_DARK, T_STEEL, T_FAIRY,
  T_NONE = 255
};
#define TYPE_COUNT 18

// Type chart in TENTHS (0 immune, 5 not-very, 10 neutral, 20 super).
// Multiplying the two defender columns gives a percentage directly:
// 20*20 = 400 (4x), 10*10 = 100 (1x), 5*10 = 50 (0.5x).
static const uint8_t TYPE_FX[TYPE_COUNT][TYPE_COUNT] = {
  { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  5,  0, 10, 10,  5, 10 },  // normal
  { 10,  5,  5, 10, 20, 20, 10, 10, 10, 10, 10, 20,  5, 10,  5, 10, 20, 10 },  // fire
  { 10, 20,  5, 10,  5, 10, 10, 10, 20, 10, 10, 10, 20, 10,  5, 10, 10, 10 },  // water
  { 10, 10, 20,  5,  5, 10, 10, 10,  0, 20, 10, 10, 10, 10,  5, 10, 10, 10 },  // electric
  { 10,  5, 20, 10,  5, 10, 10,  5, 20,  5, 10,  5, 20, 10,  5, 10,  5, 10 },  // grass
  { 10,  5,  5, 10, 20,  5, 10, 10, 20, 20, 10, 10, 10, 10, 20, 10,  5, 10 },  // ice
  { 20, 10, 10, 10, 10, 20, 10,  5, 10,  5,  5,  5, 20,  0, 10, 20, 20,  5 },  // fighting
  { 10, 10, 10, 10, 20, 10, 10,  5,  5, 10, 10, 10,  5,  5, 10, 10,  0, 20 },  // poison
  { 10, 20, 10, 20,  5, 10, 10, 20, 10,  0, 10,  5, 20, 10, 10, 10, 20, 10 },  // ground
  { 10, 10, 10,  5, 20, 10, 20, 10, 10, 10, 10, 20,  5, 10, 10, 10,  5, 10 },  // flying
  { 10, 10, 10, 10, 10, 10, 20, 20, 10, 10,  5, 10, 10, 10, 10,  0,  5, 10 },  // psychic
  { 10,  5, 10, 10, 20, 10,  5,  5, 10,  5, 20, 10, 10,  5, 10, 20,  5,  5 },  // bug
  { 10, 20, 10, 10, 10, 20,  5, 10,  5, 20, 10, 20, 10, 10, 10, 10,  5, 10 },  // rock
  {  0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 10, 10, 20, 10,  5, 10, 10 },  // ghost
  { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 10,  5,  0 },  // dragon
  { 10, 10, 10, 10, 10, 10,  5, 10, 10, 10, 20, 10, 10, 20, 10,  5, 10,  5 },  // dark
  { 10,  5,  5,  5, 10, 20, 10, 10, 10, 10, 10, 10, 20, 10, 10, 10,  5, 20 },  // steel
  { 10,  5, 10, 10, 10, 10, 20,  5, 10, 10, 10, 10, 10, 10, 20, 20,  5, 10 },  // fairy
};

// rareza: 0 = solo por evolucion, 1 = comun, 2 = raro, 3 = legendario
enum : uint8_t { R_EVO = 0, R_COMUN, R_RARO, R_LEGENDARIO };

struct DexEntry {
  const char *name;
  uint16_t evolvesTo;   // numero de dex, 0 = forma final (>255 con gen 2/3)
  uint8_t evolveLevel;
  uint8_t rarity;       // sale de huevo si > 0
  uint16_t accent;      // color RGB565 del tipo para la UI
  uint8_t bHp, bAtk, bDef, bSpe;  // base stats actuales (PokeAPI), no los de gen 1
  uint8_t bSpA, bSpD;   // ataque/defensa especial: el reparto fisico-especial
                        // vive en la especie, el individuo solo tira 4 IV
  uint8_t biome;        // 0 pradera 1 playa 2 bosque 3 volcan 4 montana 5 nieve
  uint8_t type1, type2;  // current typing; type2 = T_NONE if single-typed
};

static const DexEntry DEX_TBL[DEX_COUNT + 1] = {
  { "?", 0, 0, 0, 0x2946, 50, 50, 50, 50, 50, 50, 0 },  // 0: sin usar
  { "BISASAM", 2, 16, R_COMUN, 0x3C49, 45, 49, 49, 45, 65, 65, 2, T_GRASS, T_POISON },  // 1 grass/poison
  { "BISAKNOSP", 3, 32, R_EVO, 0x3C49, 60, 62, 63, 60, 80, 80, 2, T_GRASS, T_POISON },  // 2 grass/poison
  { "BISAFLOR", 0, 0, R_EVO, 0x3C49, 80, 82, 83, 80, 100, 100, 2, T_GRASS, T_POISON },  // 3 grass/poison
  { "GLUMANDA", 5, 16, R_COMUN, 0xEA87, 39, 52, 43, 65, 60, 50, 3, T_FIRE, T_NONE },  // 4 fire
  { "GLUTEXO", 6, 36, R_EVO, 0xEA87, 58, 64, 58, 80, 80, 65, 3, T_FIRE, T_NONE },  // 5 fire
  { "GLURAK", 0, 0, R_EVO, 0xEA87, 78, 84, 78, 100, 109, 85, 3, T_FIRE, T_FLYING },  // 6 fire/flying
  { "SCHIGGY", 8, 16, R_COMUN, 0x4C98, 44, 48, 65, 43, 50, 64, 1, T_WATER, T_NONE },  // 7 water
  { "SCHILLOK", 9, 36, R_EVO, 0x4C98, 59, 63, 80, 58, 65, 80, 1, T_WATER, T_NONE },  // 8 water
  { "TURTOK", 0, 0, R_EVO, 0x4C98, 79, 83, 100, 78, 85, 105, 1, T_WATER, T_NONE },  // 9 water
  { "RAUPY", 11, 7, R_COMUN, 0x7CC4, 45, 30, 35, 45, 20, 20, 2, T_BUG, T_NONE },  // 10 bug
  { "SAFCON", 12, 10, R_EVO, 0x7CC4, 50, 20, 55, 30, 25, 25, 2, T_BUG, T_NONE },  // 11 bug
  { "SMETTBO", 0, 0, R_EVO, 0x7CC4, 60, 45, 50, 70, 90, 80, 2, T_BUG, T_FLYING },  // 12 bug/flying
  { "HORNLIU", 14, 7, R_COMUN, 0x7CC4, 40, 35, 30, 50, 20, 20, 2, T_BUG, T_POISON },  // 13 bug/poison
  { "KOKUNA", 15, 10, R_EVO, 0x7CC4, 45, 25, 50, 35, 25, 25, 2, T_BUG, T_POISON },  // 14 bug/poison
  { "BIBOR", 0, 0, R_EVO, 0x7CC4, 65, 90, 40, 75, 45, 80, 2, T_BUG, T_POISON },  // 15 bug/poison
  { "TAUBSI", 17, 18, R_COMUN, 0x8C4D, 40, 45, 40, 56, 35, 35, 0, T_NORMAL, T_FLYING },  // 16 normal/flying
  { "TAUBOGA", 18, 36, R_EVO, 0x8C4D, 63, 60, 55, 71, 50, 50, 0, T_NORMAL, T_FLYING },  // 17 normal/flying
  { "TAUBOSS", 0, 0, R_EVO, 0x8C4D, 83, 80, 75, 101, 70, 70, 0, T_NORMAL, T_FLYING },  // 18 normal/flying
  { "RATTFRATZ", 20, 20, R_COMUN, 0x8C4D, 30, 56, 35, 72, 25, 35, 0, T_NORMAL, T_NONE },  // 19 normal
  { "RATTIKARL", 0, 0, R_EVO, 0x8C4D, 55, 81, 60, 97, 50, 70, 0, T_NORMAL, T_NONE },  // 20 normal
  { "HABITAK", 22, 20, R_COMUN, 0x8C4D, 40, 60, 30, 70, 31, 31, 0, T_NORMAL, T_FLYING },  // 21 normal/flying
  { "IBITAK", 0, 0, R_EVO, 0x8C4D, 65, 90, 65, 100, 61, 61, 0, T_NORMAL, T_FLYING },  // 22 normal/flying
  { "RETTAN", 24, 22, R_COMUN, 0x8A73, 35, 60, 44, 55, 40, 54, 0, T_POISON, T_NONE },  // 23 poison
  { "ARBOK", 0, 0, R_EVO, 0x8A73, 60, 95, 69, 80, 65, 79, 0, T_POISON, T_NONE },  // 24 poison
  { "PIKACHU", 26, 30, R_EVO, 0xBCA1, 35, 55, 40, 90, 50, 50, 0, T_ELECTRIC, T_NONE },  // 25 electric
  { "RAICHU", 0, 0, R_EVO, 0xBCA1, 60, 90, 55, 110, 90, 80, 0, T_ELECTRIC, T_NONE },  // 26 electric
  { "SANDAN", 28, 22, R_COMUN, 0xB447, 50, 75, 85, 40, 20, 30, 4, T_GROUND, T_NONE },  // 27 ground
  { "SANDAMER", 0, 0, R_EVO, 0xB447, 75, 100, 110, 65, 45, 55, 4, T_GROUND, T_NONE },  // 28 ground
  { "NIDORAN W", 30, 16, R_COMUN, 0x8A73, 55, 47, 52, 41, 40, 40, 0, T_POISON, T_NONE },  // 29 poison
  { "NIDORINA", 31, 30, R_EVO, 0x8A73, 70, 62, 67, 56, 55, 55, 0, T_POISON, T_NONE },  // 30 poison
  { "NIDOQUEEN", 0, 0, R_EVO, 0x8A73, 90, 92, 87, 76, 75, 85, 0, T_POISON, T_GROUND },  // 31 poison/ground
  { "NIDORAN M", 33, 16, R_COMUN, 0x8A73, 46, 57, 40, 50, 40, 40, 0, T_POISON, T_NONE },  // 32 poison
  { "NIDORINO", 34, 30, R_EVO, 0x8A73, 61, 72, 57, 65, 55, 55, 0, T_POISON, T_NONE },  // 33 poison
  { "NIDOKING", 0, 0, R_EVO, 0x8A73, 81, 102, 77, 85, 85, 75, 0, T_POISON, T_GROUND },  // 34 poison/ground
  { "PIEPI", 36, 30, R_EVO, 0x8C4D, 70, 45, 48, 35, 60, 65, 0, T_FAIRY, T_NONE },  // 35 fairy
  { "PIXI", 0, 0, R_EVO, 0x8C4D, 95, 70, 73, 60, 95, 90, 0, T_FAIRY, T_NONE },  // 36 fairy
  { "VULPIX", 38, 30, R_COMUN, 0xEA87, 38, 41, 40, 65, 50, 65, 3, T_FIRE, T_NONE },  // 37 fire
  { "VULNONA", 0, 0, R_EVO, 0xEA87, 73, 76, 75, 100, 81, 100, 3, T_FIRE, T_NONE },  // 38 fire
  { "PUMMELUFF", 40, 30, R_EVO, 0x8C4D, 115, 45, 20, 20, 45, 25, 0, T_NORMAL, T_FAIRY },  // 39 normal/fairy
  { "KNUDDELUFF", 0, 0, R_EVO, 0x8C4D, 140, 70, 45, 45, 85, 50, 0, T_NORMAL, T_FAIRY },  // 40 normal/fairy
  { "ZUBAT", 42, 22, R_COMUN, 0x8A73, 40, 45, 35, 55, 30, 40, 0, T_POISON, T_FLYING },  // 41 poison/flying
  { "GOLBAT", 169, 25, R_EVO, 0x8A73, 75, 80, 70, 90, 65, 75, 0, T_POISON, T_FLYING },  // 42 poison/flying
  { "MYRAPLA", 44, 21, R_COMUN, 0x3C49, 45, 50, 55, 30, 75, 65, 2, T_GRASS, T_POISON },  // 43 grass/poison
  { "DUFLOR", 45, 36, R_EVO, 0x3C49, 60, 65, 70, 40, 85, 75, 2, T_GRASS, T_POISON },  // 44 grass/poison
  { "GIFLOR", 0, 0, R_EVO, 0x3C49, 75, 80, 85, 50, 110, 90, 2, T_GRASS, T_POISON },  // 45 grass/poison
  { "PARAS", 47, 24, R_COMUN, 0x7CC4, 35, 70, 55, 25, 45, 55, 2, T_BUG, T_GRASS },  // 46 bug/grass
  { "PARASEK", 0, 0, R_EVO, 0x7CC4, 60, 95, 80, 30, 60, 80, 2, T_BUG, T_GRASS },  // 47 bug/grass
  { "BLUZUK", 49, 31, R_COMUN, 0x7CC4, 60, 55, 50, 45, 40, 55, 2, T_BUG, T_POISON },  // 48 bug/poison
  { "OMOT", 0, 0, R_EVO, 0x7CC4, 70, 65, 60, 90, 90, 75, 2, T_BUG, T_POISON },  // 49 bug/poison
  { "DIGDA", 51, 26, R_COMUN, 0xB447, 10, 55, 25, 95, 35, 45, 4, T_GROUND, T_NONE },  // 50 ground
  { "DIGDRI", 0, 0, R_EVO, 0xB447, 35, 100, 50, 120, 50, 70, 4, T_GROUND, T_NONE },  // 51 ground
  { "MAUZI", 53, 28, R_COMUN, 0x8C4D, 40, 45, 35, 90, 40, 40, 0, T_NORMAL, T_NONE },  // 52 normal
  { "SNOBILIKAT", 0, 0, R_EVO, 0x8C4D, 65, 70, 60, 115, 65, 65, 0, T_NORMAL, T_NONE },  // 53 normal
  { "ENTON", 55, 33, R_COMUN, 0x4C98, 50, 52, 48, 55, 65, 50, 1, T_WATER, T_NONE },  // 54 water
  { "ENTORON", 0, 0, R_EVO, 0x4C98, 80, 82, 78, 85, 95, 80, 1, T_WATER, T_NONE },  // 55 water
  { "MENKI", 57, 28, R_COMUN, 0xA2A5, 40, 80, 35, 70, 35, 45, 0, T_FIGHTING, T_NONE },  // 56 fighting
  { "RASAFF", 0, 0, R_EVO, 0xA2A5, 65, 105, 60, 95, 60, 70, 0, T_FIGHTING, T_NONE },  // 57 fighting
  { "FUKANO", 59, 30, R_RARO, 0xEA87, 55, 70, 45, 60, 70, 50, 3, T_FIRE, T_NONE },  // 58 fire
  { "ARKANI", 0, 0, R_EVO, 0xEA87, 90, 110, 80, 95, 100, 80, 3, T_FIRE, T_NONE },  // 59 fire
  { "QUAPSEL", 61, 25, R_COMUN, 0x4C98, 40, 50, 40, 90, 40, 40, 1, T_WATER, T_NONE },  // 60 water
  { "QUAPUTZI", 62, 36, R_EVO, 0x4C98, 65, 65, 65, 90, 50, 50, 1, T_WATER, T_NONE },  // 61 water
  { "QUAPPO", 0, 0, R_EVO, 0x4C98, 90, 95, 95, 70, 70, 90, 1, T_WATER, T_FIGHTING },  // 62 water/fighting
  { "ABRA", 64, 16, R_COMUN, 0xD28F, 25, 20, 15, 90, 105, 55, 0, T_PSYCHIC, T_NONE },  // 63 psychic
  { "KADABRA", 65, 40, R_EVO, 0xD28F, 40, 35, 30, 105, 120, 70, 0, T_PSYCHIC, T_NONE },  // 64 psychic
  { "SIMSALA", 0, 0, R_EVO, 0xD28F, 55, 50, 45, 120, 135, 95, 0, T_PSYCHIC, T_NONE },  // 65 psychic
  { "MACHOLLO", 67, 28, R_COMUN, 0xA2A5, 70, 80, 50, 35, 35, 35, 0, T_FIGHTING, T_NONE },  // 66 fighting
  { "MASCHOCK", 68, 40, R_EVO, 0xA2A5, 80, 100, 70, 45, 50, 60, 0, T_FIGHTING, T_NONE },  // 67 fighting
  { "MACHOMEI", 0, 0, R_EVO, 0xA2A5, 90, 130, 80, 55, 65, 85, 0, T_FIGHTING, T_NONE },  // 68 fighting
  { "KNOFENSA", 70, 21, R_COMUN, 0x3C49, 50, 75, 35, 40, 70, 30, 2, T_GRASS, T_POISON },  // 69 grass/poison
  { "ULTRIGARIA", 71, 36, R_EVO, 0x3C49, 65, 90, 50, 55, 85, 45, 2, T_GRASS, T_POISON },  // 70 grass/poison
  { "SARZENIA", 0, 0, R_EVO, 0x3C49, 80, 105, 65, 70, 100, 70, 2, T_GRASS, T_POISON },  // 71 grass/poison
  { "TENTACHA", 73, 30, R_COMUN, 0x4C98, 40, 40, 35, 70, 50, 100, 1, T_WATER, T_POISON },  // 72 water/poison
  { "TENTOXA", 0, 0, R_EVO, 0x4C98, 80, 70, 65, 100, 80, 120, 1, T_WATER, T_POISON },  // 73 water/poison
  { "KLEINSTEIN", 75, 25, R_COMUN, 0x9407, 40, 80, 100, 20, 30, 30, 4, T_ROCK, T_GROUND },  // 74 rock/ground
  { "GEOROK", 76, 40, R_EVO, 0x9407, 55, 95, 115, 35, 45, 45, 4, T_ROCK, T_GROUND },  // 75 rock/ground
  { "GEOWAZ", 0, 0, R_EVO, 0x9407, 80, 120, 130, 45, 55, 65, 4, T_ROCK, T_GROUND },  // 76 rock/ground
  { "PONITA", 78, 40, R_RARO, 0xEA87, 50, 85, 55, 90, 65, 65, 3, T_FIRE, T_NONE },  // 77 fire
  { "GALLOPA", 0, 0, R_EVO, 0xEA87, 65, 100, 70, 105, 80, 80, 3, T_FIRE, T_NONE },  // 78 fire
  { "FLEGMON", 80, 37, R_COMUN, 0x4C98, 90, 65, 65, 15, 40, 40, 1, T_WATER, T_PSYCHIC },  // 79 water/psychic
  { "LAHMUS", 0, 0, R_EVO, 0x4C98, 95, 75, 110, 30, 100, 80, 1, T_WATER, T_PSYCHIC },  // 80 water/psychic
  { "MAGNETILO", 82, 30, R_COMUN, 0xBCA1, 25, 35, 70, 45, 95, 55, 0, T_ELECTRIC, T_STEEL },  // 81 electric/steel
  { "MAGNETON", 462, 30, R_EVO, 0xBCA1, 50, 60, 95, 70, 120, 70, 0, T_ELECTRIC, T_STEEL },  // 82 electric/steel
  { "PORENTA", 0, 0, R_RARO, 0x8C4D, 52, 90, 55, 60, 58, 62, 0, T_NORMAL, T_FLYING },  // 83 normal/flying
  { "DODU", 85, 31, R_COMUN, 0x8C4D, 35, 85, 45, 75, 35, 35, 0, T_NORMAL, T_FLYING },  // 84 normal/flying
  { "DODRI", 0, 0, R_EVO, 0x8C4D, 60, 110, 70, 110, 60, 60, 0, T_NORMAL, T_FLYING },  // 85 normal/flying
  { "JUROB", 87, 34, R_COMUN, 0x4C98, 65, 45, 55, 45, 45, 70, 1, T_WATER, T_NONE },  // 86 water
  { "JUGONG", 0, 0, R_EVO, 0x4C98, 90, 70, 80, 70, 70, 95, 1, T_WATER, T_ICE },  // 87 water/ice
  { "SLEIMA", 89, 38, R_RARO, 0x8A73, 80, 80, 50, 25, 40, 50, 0, T_POISON, T_NONE },  // 88 poison
  { "SLEIMOK", 0, 0, R_EVO, 0x8A73, 105, 105, 75, 50, 65, 100, 0, T_POISON, T_NONE },  // 89 poison
  { "MUSCHAS", 91, 30, R_COMUN, 0x4C98, 30, 65, 100, 40, 45, 25, 1, T_WATER, T_NONE },  // 90 water
  { "AUSTOS", 0, 0, R_EVO, 0x4C98, 50, 95, 180, 70, 85, 45, 1, T_WATER, T_ICE },  // 91 water/ice
  { "NEBULAK", 93, 25, R_COMUN, 0x6AD3, 30, 35, 30, 80, 100, 35, 0, T_GHOST, T_POISON },  // 92 ghost/poison
  { "ALPOLLO", 94, 40, R_EVO, 0x6AD3, 45, 50, 45, 95, 115, 55, 0, T_GHOST, T_POISON },  // 93 ghost/poison
  { "GENGAR", 0, 0, R_EVO, 0x6AD3, 60, 65, 60, 110, 130, 75, 0, T_GHOST, T_POISON },  // 94 ghost/poison
  { "ONIX", 208, 40, R_RARO, 0x9407, 35, 45, 160, 70, 30, 45, 4, T_ROCK, T_GROUND },  // 95 rock/ground
  { "TRAUMATO", 97, 26, R_COMUN, 0xD28F, 60, 48, 45, 42, 43, 90, 0, T_PSYCHIC, T_NONE },  // 96 psychic
  { "HYPNO", 0, 0, R_EVO, 0xD28F, 85, 73, 70, 67, 73, 115, 0, T_PSYCHIC, T_NONE },  // 97 psychic
  { "KRABBY", 99, 28, R_COMUN, 0x4C98, 30, 105, 90, 50, 25, 25, 1, T_WATER, T_NONE },  // 98 water
  { "KINGLER", 0, 0, R_EVO, 0x4C98, 55, 130, 115, 75, 50, 50, 1, T_WATER, T_NONE },  // 99 water
  { "VOLTOBAL", 101, 30, R_COMUN, 0xBCA1, 40, 30, 50, 100, 55, 55, 0, T_ELECTRIC, T_NONE },  // 100 electric
  { "LEKTROBAL", 0, 0, R_EVO, 0xBCA1, 60, 50, 70, 150, 80, 80, 0, T_ELECTRIC, T_NONE },  // 101 electric
  { "OWEI", 103, 30, R_COMUN, 0x3C49, 60, 40, 80, 40, 60, 45, 2, T_GRASS, T_PSYCHIC },  // 102 grass/psychic
  { "KOKOWEI", 0, 0, R_EVO, 0x3C49, 95, 95, 85, 55, 125, 75, 2, T_GRASS, T_PSYCHIC },  // 103 grass/psychic
  { "TRAGOSSO", 105, 28, R_COMUN, 0xB447, 50, 50, 95, 35, 40, 50, 4, T_GROUND, T_NONE },  // 104 ground
  { "KNOGGA", 0, 0, R_EVO, 0xB447, 60, 80, 110, 45, 50, 80, 4, T_GROUND, T_NONE },  // 105 ground
  { "KICKLEE", 0, 0, R_EVO, 0xA2A5, 50, 120, 53, 87, 35, 110, 0, T_FIGHTING, T_NONE },  // 106 fighting
  { "NOCKCHAN", 0, 0, R_RARO, 0xA2A5, 50, 105, 79, 76, 35, 110, 0, T_FIGHTING, T_NONE },  // 107 fighting
  { "SCHLURP", 463, 30, R_RARO, 0x8C4D, 90, 55, 75, 30, 60, 75, 0, T_NORMAL, T_NONE },  // 108 normal
  { "SMOGON", 110, 35, R_COMUN, 0x8A73, 40, 65, 95, 35, 60, 45, 0, T_POISON, T_NONE },  // 109 poison
  { "SMOGMOG", 0, 0, R_EVO, 0x8A73, 65, 90, 120, 60, 85, 70, 0, T_POISON, T_NONE },  // 110 poison
  { "RIHORN", 112, 42, R_RARO, 0xB447, 80, 85, 95, 25, 30, 30, 4, T_GROUND, T_ROCK },  // 111 ground/rock
  { "RIZEROS", 464, 40, R_EVO, 0xB447, 105, 130, 120, 40, 45, 45, 4, T_GROUND, T_ROCK },  // 112 ground/rock
  { "CHANEIRA", 242, 25, R_EVO, 0x8C4D, 250, 5, 5, 50, 35, 105, 0, T_NORMAL, T_NONE },  // 113 normal
  { "TANGELA", 465, 30, R_RARO, 0x3C49, 65, 55, 115, 60, 100, 40, 2, T_GRASS, T_NONE },  // 114 grass
  { "KANGAMA", 0, 0, R_RARO, 0x8C4D, 105, 95, 80, 90, 40, 80, 0, T_NORMAL, T_NONE },  // 115 normal
  { "SEEPER", 117, 32, R_COMUN, 0x4C98, 30, 40, 70, 60, 70, 25, 1, T_WATER, T_NONE },  // 116 water
  { "SEEMON", 230, 40, R_EVO, 0x4C98, 55, 65, 95, 85, 95, 45, 1, T_WATER, T_NONE },  // 117 water
  { "GOLDINI", 119, 33, R_COMUN, 0x4C98, 45, 67, 60, 63, 35, 50, 1, T_WATER, T_NONE },  // 118 water
  { "GOLKING", 0, 0, R_EVO, 0x4C98, 80, 92, 65, 68, 65, 80, 1, T_WATER, T_NONE },  // 119 water
  { "STERNDU", 121, 30, R_COMUN, 0x4C98, 30, 45, 55, 85, 70, 55, 1, T_WATER, T_NONE },  // 120 water
  { "STARMIE", 0, 0, R_EVO, 0x4C98, 60, 75, 85, 115, 100, 85, 1, T_WATER, T_PSYCHIC },  // 121 water/psychic
  { "PANTIMOS", 0, 0, R_EVO, 0xD28F, 40, 45, 65, 90, 100, 120, 0, T_PSYCHIC, T_FAIRY },  // 122 psychic/fairy
  { "SICHLOR", 212, 40, R_RARO, 0x7CC4, 70, 110, 80, 105, 55, 80, 2, T_BUG, T_FLYING },  // 123 bug/flying
  { "ROSSANA", 0, 0, R_EVO, 0x4DB8, 65, 50, 35, 95, 115, 95, 5, T_ICE, T_PSYCHIC },  // 124 ice/psychic
  { "ELEKTEK", 466, 40, R_EVO, 0xBCA1, 65, 83, 57, 105, 95, 85, 0, T_ELECTRIC, T_NONE },  // 125 electric
  { "MAGMAR", 467, 40, R_EVO, 0xEA87, 65, 95, 57, 93, 100, 85, 3, T_FIRE, T_NONE },  // 126 fire
  { "PINSIR", 0, 0, R_RARO, 0x7CC4, 65, 125, 100, 85, 55, 70, 2, T_BUG, T_NONE },  // 127 bug
  { "TAUROS", 0, 0, R_RARO, 0x8C4D, 75, 100, 95, 110, 40, 70, 0, T_NORMAL, T_NONE },  // 128 normal
  { "KARPADOR", 130, 20, R_COMUN, 0x4C98, 20, 10, 55, 80, 15, 20, 1, T_WATER, T_NONE },  // 129 water
  { "GARADOS", 0, 0, R_EVO, 0x4C98, 95, 125, 79, 81, 60, 100, 1, T_WATER, T_FLYING },  // 130 water/flying
  { "LAPRAS", 0, 0, R_RARO, 0x4C98, 130, 85, 80, 60, 85, 95, 1, T_WATER, T_ICE },  // 131 water/ice
  { "DITTO", 0, 0, R_RARO, 0x8C4D, 48, 48, 48, 48, 48, 48, 0, T_NORMAL, T_NONE },  // 132 normal
  { "EVOLI", 134, 30, R_COMUN, 0x8C4D, 55, 55, 50, 55, 45, 65, 0, T_NORMAL, T_NONE },  // 133 normal
  { "AQUANA", 0, 0, R_EVO, 0x4C98, 130, 65, 60, 65, 110, 95, 1, T_WATER, T_NONE },  // 134 water
  { "BLITZA", 0, 0, R_EVO, 0xBCA1, 65, 65, 60, 130, 110, 95, 0, T_ELECTRIC, T_NONE },  // 135 electric
  { "FLAMARA", 0, 0, R_EVO, 0xEA87, 65, 130, 60, 65, 95, 110, 3, T_FIRE, T_NONE },  // 136 fire
  { "PORYGON", 233, 40, R_RARO, 0x8C4D, 65, 60, 70, 40, 85, 75, 0, T_NORMAL, T_NONE },  // 137 normal
  { "AMONITAS", 139, 40, R_RARO, 0x9407, 35, 40, 100, 35, 90, 55, 1, T_ROCK, T_WATER },  // 138 rock/water
  { "AMOROSO", 0, 0, R_EVO, 0x9407, 70, 60, 125, 55, 115, 70, 1, T_ROCK, T_WATER },  // 139 rock/water
  { "KABUTO", 141, 40, R_RARO, 0x9407, 30, 80, 90, 55, 55, 45, 1, T_ROCK, T_WATER },  // 140 rock/water
  { "KABUTOPS", 0, 0, R_EVO, 0x9407, 60, 115, 105, 80, 65, 70, 1, T_ROCK, T_WATER },  // 141 rock/water
  { "AERODACTYL", 0, 0, R_RARO, 0x9407, 80, 105, 65, 130, 60, 75, 4, T_ROCK, T_FLYING },  // 142 rock/flying
  { "RELAXO", 0, 0, R_EVO, 0x8C4D, 160, 110, 65, 30, 65, 110, 0, T_NORMAL, T_NONE },  // 143 normal
  { "ARKTOS", 0, 0, R_LEGENDARIO, 0x4DB8, 90, 85, 100, 85, 95, 125, 5, T_ICE, T_FLYING },  // 144 ice/flying
  { "ZAPDOS", 0, 0, R_LEGENDARIO, 0xBCA1, 90, 90, 85, 100, 125, 90, 0, T_ELECTRIC, T_FLYING },  // 145 electric/flying
  { "LAVADOS", 0, 0, R_LEGENDARIO, 0xEA87, 90, 100, 90, 90, 125, 85, 3, T_FIRE, T_FLYING },  // 146 fire/flying
  { "DRATINI", 148, 30, R_RARO, 0x5A98, 41, 64, 45, 50, 50, 50, 1, T_DRAGON, T_NONE },  // 147 dragon
  { "DRAGONIR", 149, 55, R_EVO, 0x5A98, 61, 84, 65, 70, 70, 70, 1, T_DRAGON, T_NONE },  // 148 dragon
  { "DRAGORAN", 0, 0, R_EVO, 0x5A98, 91, 134, 95, 80, 100, 100, 1, T_DRAGON, T_FLYING },  // 149 dragon/flying
  { "MEWTU", 0, 0, R_LEGENDARIO, 0xD28F, 106, 110, 90, 130, 154, 90, 0, T_PSYCHIC, T_NONE },  // 150 psychic
  { "MEW", 0, 0, R_LEGENDARIO, 0xD28F, 100, 100, 100, 100, 100, 100, 0, T_PSYCHIC, T_NONE },  // 151 psychic
  { "ENDIVIE", 153, 16, R_RARO, 0x3C49, 45, 49, 65, 45, 49, 65, 2, T_GRASS, T_NONE },  // 152 grass
  { "LORBLATT", 154, 32, R_EVO, 0x3C49, 60, 62, 80, 60, 63, 80, 2, T_GRASS, T_NONE },  // 153 grass
  { "MEGANIE", 0, 0, R_EVO, 0x3C49, 80, 82, 100, 80, 83, 100, 2, T_GRASS, T_NONE },  // 154 grass
  { "FEURIGEL", 156, 14, R_RARO, 0xEA87, 39, 52, 43, 65, 60, 50, 3, T_FIRE, T_NONE },  // 155 fire
  { "IGELAVAR", 157, 36, R_EVO, 0xEA87, 58, 64, 58, 80, 80, 65, 3, T_FIRE, T_NONE },  // 156 fire
  { "TORNUPTO", 0, 0, R_EVO, 0xEA87, 78, 84, 78, 100, 109, 85, 3, T_FIRE, T_NONE },  // 157 fire
  { "KARNIMANI", 159, 18, R_RARO, 0x4C98, 50, 65, 64, 43, 44, 48, 1, T_WATER, T_NONE },  // 158 water
  { "TYRACROC", 160, 30, R_EVO, 0x4C98, 65, 80, 80, 58, 59, 63, 1, T_WATER, T_NONE },  // 159 water
  { "IMPERGATOR", 0, 0, R_EVO, 0x4C98, 85, 105, 100, 78, 79, 83, 1, T_WATER, T_NONE },  // 160 water
  { "WIESOR", 162, 15, R_COMUN, 0x8C4D, 35, 46, 34, 20, 35, 45, 0, T_NORMAL, T_NONE },  // 161 normal
  { "WIESENIOR", 0, 0, R_EVO, 0x8C4D, 85, 76, 64, 90, 45, 55, 0, T_NORMAL, T_NONE },  // 162 normal
  { "HOOTHOOT", 164, 20, R_COMUN, 0x8C4D, 60, 30, 30, 50, 36, 56, 0, T_NORMAL, T_FLYING },  // 163 normal/flying
  { "NOCTUH", 0, 0, R_EVO, 0x8C4D, 100, 50, 50, 70, 86, 96, 0, T_NORMAL, T_FLYING },  // 164 normal/flying
  { "LEDYBA", 166, 18, R_COMUN, 0x7CC4, 40, 20, 30, 55, 40, 80, 2, T_BUG, T_FLYING },  // 165 bug/flying
  { "LEDIAN", 0, 0, R_EVO, 0x7CC4, 55, 35, 50, 85, 55, 110, 2, T_BUG, T_FLYING },  // 166 bug/flying
  { "WEBARAK", 168, 22, R_COMUN, 0x7CC4, 40, 60, 40, 30, 40, 40, 2, T_BUG, T_POISON },  // 167 bug/poison
  { "ARIADOS", 0, 0, R_EVO, 0x7CC4, 70, 90, 70, 40, 60, 70, 2, T_BUG, T_POISON },  // 168 bug/poison
  { "IKSBAT", 0, 0, R_EVO, 0x8A73, 85, 90, 80, 130, 70, 80, 0, T_POISON, T_FLYING },  // 169 poison/flying
  { "LAMPI", 171, 27, R_COMUN, 0x4C98, 75, 38, 38, 67, 56, 56, 1, T_WATER, T_ELECTRIC },  // 170 water/electric
  { "LANTURN", 0, 0, R_EVO, 0x4C98, 125, 58, 58, 67, 76, 76, 1, T_WATER, T_ELECTRIC },  // 171 water/electric
  { "PICHU", 25, 25, R_COMUN, 0xBCA1, 20, 40, 15, 60, 35, 35, 0, T_ELECTRIC, T_NONE },  // 172 electric
  { "PII", 35, 25, R_COMUN, 0xC333, 50, 25, 28, 15, 45, 55, 0, T_FAIRY, T_NONE },  // 173 fairy
  { "FLUFFELUFF", 39, 25, R_COMUN, 0x8C4D, 90, 30, 15, 15, 40, 20, 0, T_NORMAL, T_FAIRY },  // 174 normal/fairy
  { "TOGEPI", 176, 25, R_COMUN, 0xC333, 35, 20, 65, 20, 40, 65, 0, T_FAIRY, T_NONE },  // 175 fairy
  { "TOGETIC", 468, 30, R_EVO, 0xC333, 55, 40, 85, 40, 80, 105, 0, T_FAIRY, T_FLYING },  // 176 fairy/flying
  { "NATU", 178, 25, R_COMUN, 0xD28F, 40, 50, 45, 70, 70, 45, 0, T_PSYCHIC, T_FLYING },  // 177 psychic/flying
  { "XATU", 0, 0, R_EVO, 0xD28F, 65, 75, 70, 95, 95, 70, 0, T_PSYCHIC, T_FLYING },  // 178 psychic/flying
  { "VOLTILAMM", 180, 15, R_COMUN, 0xBCA1, 55, 40, 40, 35, 65, 45, 0, T_ELECTRIC, T_NONE },  // 179 electric
  { "WAATY", 181, 30, R_EVO, 0xBCA1, 70, 55, 55, 45, 80, 60, 0, T_ELECTRIC, T_NONE },  // 180 electric
  { "AMPHAROS", 0, 0, R_EVO, 0xBCA1, 90, 75, 85, 55, 115, 90, 0, T_ELECTRIC, T_NONE },  // 181 electric
  { "BLUBELLA", 0, 0, R_RARO, 0x3C49, 75, 80, 95, 50, 90, 100, 2, T_GRASS, T_NONE },  // 182 grass
  { "MARILL", 184, 18, R_EVO, 0x4C98, 70, 20, 50, 40, 20, 50, 1, T_WATER, T_FAIRY },  // 183 water/fairy
  { "AZUMARILL", 0, 0, R_EVO, 0x4C98, 100, 50, 80, 50, 60, 80, 1, T_WATER, T_FAIRY },  // 184 water/fairy
  { "MOGELBAUM", 0, 0, R_EVO, 0x9407, 70, 100, 115, 30, 30, 65, 4, T_ROCK, T_NONE },  // 185 rock
  { "QUAXO", 0, 0, R_RARO, 0x4C98, 90, 75, 75, 70, 90, 100, 1, T_WATER, T_NONE },  // 186 water
  { "HOPPSPROSS", 188, 18, R_COMUN, 0x3C49, 35, 35, 40, 50, 35, 55, 2, T_GRASS, T_FLYING },  // 187 grass/flying
  { "HUBELUPF", 189, 27, R_EVO, 0x3C49, 55, 45, 50, 80, 45, 65, 2, T_GRASS, T_FLYING },  // 188 grass/flying
  { "PAPUNGHA", 0, 0, R_EVO, 0x3C49, 75, 55, 70, 110, 55, 95, 2, T_GRASS, T_FLYING },  // 189 grass/flying
  { "GRIFFEL", 424, 30, R_RARO, 0x8C4D, 55, 70, 55, 85, 40, 55, 0, T_NORMAL, T_NONE },  // 190 normal
  { "SONNKERN", 192, 30, R_COMUN, 0x3C49, 30, 30, 30, 30, 30, 30, 2, T_GRASS, T_NONE },  // 191 grass
  { "SONNFLORA", 0, 0, R_EVO, 0x3C49, 75, 75, 55, 30, 105, 85, 2, T_GRASS, T_NONE },  // 192 grass
  { "YANMA", 469, 30, R_COMUN, 0x7CC4, 65, 65, 45, 95, 75, 45, 2, T_BUG, T_FLYING },  // 193 bug/flying
  { "FELINO", 195, 20, R_COMUN, 0x4C98, 55, 45, 45, 15, 25, 25, 1, T_WATER, T_GROUND },  // 194 water/ground
  { "MORLORD", 0, 0, R_EVO, 0x4C98, 95, 85, 85, 35, 65, 65, 1, T_WATER, T_GROUND },  // 195 water/ground
  { "PSIANA", 0, 0, R_EVO, 0xD28F, 65, 65, 60, 110, 130, 95, 0, T_PSYCHIC, T_NONE },  // 196 psychic
  { "NACHTARA", 0, 0, R_EVO, 0x5A47, 95, 65, 110, 65, 60, 130, 2, T_DARK, T_NONE },  // 197 dark
  { "KRAMURX", 430, 30, R_RARO, 0x5A47, 60, 85, 42, 91, 85, 42, 2, T_DARK, T_FLYING },  // 198 dark/flying
  { "LASCHOKING", 0, 0, R_COMUN, 0x4C98, 95, 75, 80, 30, 100, 110, 1, T_WATER, T_PSYCHIC },  // 199 water/psychic
  { "TRAUNFUGIL", 429, 30, R_RARO, 0x6AD3, 60, 60, 60, 85, 85, 85, 0, T_GHOST, T_NONE },  // 200 ghost
  { "ICOGNITO", 0, 0, R_COMUN, 0xD28F, 48, 72, 48, 48, 72, 48, 0, T_PSYCHIC, T_NONE },  // 201 psychic
  { "WOINGENAU", 0, 0, R_EVO, 0xD28F, 190, 33, 58, 33, 33, 58, 0, T_PSYCHIC, T_NONE },  // 202 psychic
  { "GIRAFARIG", 0, 0, R_COMUN, 0x8C4D, 70, 80, 65, 85, 90, 65, 0, T_NORMAL, T_PSYCHIC },  // 203 normal/psychic
  { "TANNZA", 205, 31, R_COMUN, 0x7CC4, 50, 65, 90, 15, 35, 35, 2, T_BUG, T_NONE },  // 204 bug
  { "FORSTELLKA", 0, 0, R_EVO, 0x7CC4, 75, 90, 140, 40, 60, 60, 2, T_BUG, T_STEEL },  // 205 bug/steel
  { "DUMMISEL", 0, 0, R_COMUN, 0x8C4D, 100, 70, 70, 45, 65, 65, 0, T_NORMAL, T_NONE },  // 206 normal
  { "SKORGLA", 472, 30, R_COMUN, 0xB447, 65, 75, 105, 85, 35, 65, 4, T_GROUND, T_FLYING },  // 207 ground/flying
  { "STAHLOS", 0, 0, R_EVO, 0x6BF1, 75, 85, 200, 30, 55, 65, 4, T_STEEL, T_GROUND },  // 208 steel/ground
  { "SNUBBULL", 210, 23, R_COMUN, 0xC333, 60, 80, 50, 30, 40, 40, 0, T_FAIRY, T_NONE },  // 209 fairy
  { "GRANBULL", 0, 0, R_EVO, 0xC333, 90, 120, 75, 45, 60, 60, 0, T_FAIRY, T_NONE },  // 210 fairy
  { "BALDORFISH", 0, 0, R_RARO, 0x4C98, 65, 95, 85, 85, 55, 55, 1, T_WATER, T_POISON },  // 211 water/poison
  { "SCHEROX", 0, 0, R_EVO, 0x7CC4, 70, 130, 100, 65, 55, 80, 2, T_BUG, T_STEEL },  // 212 bug/steel
  { "POTTROTT", 0, 0, R_COMUN, 0x7CC4, 20, 10, 230, 5, 10, 230, 2, T_BUG, T_ROCK },  // 213 bug/rock
  { "SKARABORN", 0, 0, R_RARO, 0x7CC4, 80, 125, 75, 85, 40, 95, 2, T_BUG, T_FIGHTING },  // 214 bug/fighting
  { "SNIEBEL", 461, 30, R_COMUN, 0x5A47, 55, 95, 55, 115, 35, 75, 2, T_DARK, T_ICE },  // 215 dark/ice
  { "TEDDIURSA", 217, 30, R_COMUN, 0x8C4D, 60, 80, 50, 40, 50, 50, 0, T_NORMAL, T_NONE },  // 216 normal
  { "URSARING", 0, 0, R_EVO, 0x8C4D, 90, 130, 75, 55, 75, 75, 0, T_NORMAL, T_NONE },  // 217 normal
  { "SCHNECKMAG", 219, 38, R_COMUN, 0xEA87, 40, 40, 40, 20, 70, 40, 3, T_FIRE, T_NONE },  // 218 fire
  { "MAGCARGO", 0, 0, R_EVO, 0xEA87, 60, 50, 120, 30, 90, 80, 3, T_FIRE, T_ROCK },  // 219 fire/rock
  { "QUIEKEL", 221, 33, R_COMUN, 0x4DB8, 50, 50, 40, 50, 30, 30, 5, T_ICE, T_GROUND },  // 220 ice/ground
  { "KEIFEL", 473, 30, R_EVO, 0x4DB8, 100, 100, 80, 50, 60, 60, 5, T_ICE, T_GROUND },  // 221 ice/ground
  { "CORASONN", 0, 0, R_COMUN, 0x4C98, 65, 55, 95, 35, 65, 95, 1, T_WATER, T_ROCK },  // 222 water/rock
  { "REMORAID", 224, 25, R_COMUN, 0x4C98, 35, 65, 35, 65, 65, 35, 1, T_WATER, T_NONE },  // 223 water
  { "OCTILLERY", 0, 0, R_EVO, 0x4C98, 75, 105, 75, 45, 105, 75, 1, T_WATER, T_NONE },  // 224 water
  { "BOTOGEL", 0, 0, R_RARO, 0x4DB8, 45, 55, 45, 75, 65, 45, 5, T_ICE, T_FLYING },  // 225 ice/flying
  { "MANTAX", 0, 0, R_EVO, 0x4C98, 85, 40, 70, 70, 80, 140, 1, T_WATER, T_FLYING },  // 226 water/flying
  { "PANZAERON", 0, 0, R_RARO, 0x6BF1, 65, 80, 140, 70, 40, 70, 4, T_STEEL, T_FLYING },  // 227 steel/flying
  { "HUNDUSTER", 229, 24, R_COMUN, 0x5A47, 45, 60, 30, 65, 80, 50, 2, T_DARK, T_FIRE },  // 228 dark/fire
  { "HUNDEMON", 0, 0, R_EVO, 0x5A47, 75, 90, 50, 95, 110, 80, 2, T_DARK, T_FIRE },  // 229 dark/fire
  { "SEEDRAKING", 0, 0, R_EVO, 0x4C98, 75, 95, 95, 85, 95, 95, 1, T_WATER, T_DRAGON },  // 230 water/dragon
  { "PHANPY", 232, 25, R_COMUN, 0xB447, 90, 60, 60, 40, 40, 40, 4, T_GROUND, T_NONE },  // 231 ground
  { "DONPHAN", 0, 0, R_EVO, 0xB447, 90, 120, 120, 50, 60, 60, 4, T_GROUND, T_NONE },  // 232 ground
  { "PORYGON2", 474, 40, R_EVO, 0x8C4D, 85, 80, 90, 60, 105, 95, 0, T_NORMAL, T_NONE },  // 233 normal
  { "DAMHIRPLEX", 0, 0, R_RARO, 0x8C4D, 73, 95, 62, 85, 85, 65, 0, T_NORMAL, T_NONE },  // 234 normal
  { "FARBEAGLE", 0, 0, R_RARO, 0x8C4D, 55, 20, 35, 75, 20, 45, 0, T_NORMAL, T_NONE },  // 235 normal
  { "RABAUZ", 106, 20, R_COMUN, 0xA2A5, 35, 35, 35, 35, 35, 35, 0, T_FIGHTING, T_NONE },  // 236 fighting
  { "KAPOERA", 0, 0, R_RARO, 0xA2A5, 50, 95, 95, 70, 35, 110, 0, T_FIGHTING, T_NONE },  // 237 fighting
  { "KUSSILLA", 124, 30, R_RARO, 0x4DB8, 45, 30, 15, 65, 85, 65, 5, T_ICE, T_PSYCHIC },  // 238 ice/psychic
  { "ELEKID", 125, 30, R_RARO, 0xBCA1, 45, 63, 37, 95, 65, 55, 0, T_ELECTRIC, T_NONE },  // 239 electric
  { "MAGBY", 126, 30, R_RARO, 0xEA87, 45, 75, 37, 83, 70, 55, 3, T_FIRE, T_NONE },  // 240 fire
  { "MILTANK", 0, 0, R_RARO, 0x8C4D, 95, 80, 105, 100, 40, 70, 0, T_NORMAL, T_NONE },  // 241 normal
  { "HEITEIRA", 0, 0, R_EVO, 0x8C4D, 255, 10, 10, 55, 75, 135, 0, T_NORMAL, T_NONE },  // 242 normal
  { "RAIKOU", 0, 0, R_LEGENDARIO, 0xBCA1, 90, 85, 75, 115, 115, 100, 0, T_ELECTRIC, T_NONE },  // 243 electric
  { "ENTEI", 0, 0, R_LEGENDARIO, 0xEA87, 115, 115, 85, 100, 90, 75, 3, T_FIRE, T_NONE },  // 244 fire
  { "SUICUNE", 0, 0, R_LEGENDARIO, 0x4C98, 100, 75, 115, 85, 90, 115, 1, T_WATER, T_NONE },  // 245 water
  { "LARVITAR", 247, 30, R_RARO, 0x9407, 50, 64, 50, 41, 45, 50, 4, T_ROCK, T_GROUND },  // 246 rock/ground
  { "PUPITAR", 248, 55, R_EVO, 0x9407, 70, 84, 70, 51, 65, 70, 4, T_ROCK, T_GROUND },  // 247 rock/ground
  { "DESPOTAR", 0, 0, R_EVO, 0x9407, 100, 134, 110, 61, 95, 100, 4, T_ROCK, T_DARK },  // 248 rock/dark
  { "LUGIA", 0, 0, R_LEGENDARIO, 0xD28F, 106, 90, 130, 110, 90, 154, 0, T_PSYCHIC, T_FLYING },  // 249 psychic/flying
  { "HO-OH", 0, 0, R_LEGENDARIO, 0xEA87, 106, 130, 90, 90, 110, 154, 3, T_FIRE, T_FLYING },  // 250 fire/flying
  { "CELEBI", 0, 0, R_LEGENDARIO, 0xD28F, 100, 100, 100, 100, 100, 100, 0, T_PSYCHIC, T_GRASS },  // 251 psychic/grass
  { "GECKARBOR", 253, 16, R_RARO, 0x3C49, 40, 45, 35, 70, 65, 55, 2, T_GRASS, T_NONE },  // 252 grass
  { "REPTAIN", 254, 36, R_EVO, 0x3C49, 50, 65, 45, 95, 85, 65, 2, T_GRASS, T_NONE },  // 253 grass
  { "GEWALDRO", 0, 0, R_EVO, 0x3C49, 70, 85, 65, 120, 105, 85, 2, T_GRASS, T_NONE },  // 254 grass
  { "FLEMMLI", 256, 16, R_RARO, 0xEA87, 45, 60, 40, 45, 70, 50, 3, T_FIRE, T_NONE },  // 255 fire
  { "JUNGGLUT", 257, 36, R_EVO, 0xEA87, 60, 85, 60, 55, 85, 60, 3, T_FIRE, T_FIGHTING },  // 256 fire/fighting
  { "LOHGOCK", 0, 0, R_EVO, 0xEA87, 80, 120, 70, 80, 110, 70, 3, T_FIRE, T_FIGHTING },  // 257 fire/fighting
  { "HYDROPI", 259, 16, R_RARO, 0x4C98, 50, 70, 50, 40, 50, 50, 1, T_WATER, T_NONE },  // 258 water
  { "MOORABBEL", 260, 36, R_EVO, 0x4C98, 70, 85, 70, 50, 60, 70, 1, T_WATER, T_GROUND },  // 259 water/ground
  { "SUMPEX", 0, 0, R_EVO, 0x4C98, 100, 110, 90, 60, 85, 90, 1, T_WATER, T_GROUND },  // 260 water/ground
  { "FIFFYEN", 262, 18, R_COMUN, 0x5A47, 35, 55, 35, 35, 30, 30, 2, T_DARK, T_NONE },  // 261 dark
  { "MAGNAYEN", 0, 0, R_EVO, 0x5A47, 70, 90, 70, 70, 60, 60, 2, T_DARK, T_NONE },  // 262 dark
  { "ZIGZACHS", 264, 20, R_COMUN, 0x8C4D, 38, 30, 41, 60, 30, 41, 0, T_NORMAL, T_NONE },  // 263 normal
  { "GERADAKS", 0, 0, R_EVO, 0x8C4D, 78, 70, 61, 100, 50, 61, 0, T_NORMAL, T_NONE },  // 264 normal
  { "WAUMPEL", 266, 7, R_COMUN, 0x7CC4, 45, 45, 35, 20, 20, 30, 2, T_BUG, T_NONE },  // 265 bug
  { "SCHALOKO", 267, 10, R_EVO, 0x7CC4, 50, 35, 55, 15, 25, 25, 2, T_BUG, T_NONE },  // 266 bug
  { "PAPINELLA", 0, 0, R_EVO, 0x7CC4, 60, 70, 50, 65, 100, 50, 2, T_BUG, T_FLYING },  // 267 bug/flying
  { "PANEKON", 269, 10, R_COMUN, 0x7CC4, 50, 35, 55, 15, 25, 25, 2, T_BUG, T_NONE },  // 268 bug
  { "PUDOX", 0, 0, R_EVO, 0x7CC4, 60, 50, 70, 65, 50, 90, 2, T_BUG, T_POISON },  // 269 bug/poison
  { "LOTURZEL", 271, 14, R_COMUN, 0x4C98, 40, 30, 30, 30, 40, 50, 1, T_WATER, T_GRASS },  // 270 water/grass
  { "LOMBRERO", 272, 30, R_EVO, 0x4C98, 60, 50, 50, 50, 60, 70, 1, T_WATER, T_GRASS },  // 271 water/grass
  { "KAPPALORES", 0, 0, R_EVO, 0x4C98, 80, 70, 70, 70, 90, 100, 1, T_WATER, T_GRASS },  // 272 water/grass
  { "SAMURZEL", 274, 14, R_COMUN, 0x3C49, 40, 40, 50, 30, 30, 30, 2, T_GRASS, T_NONE },  // 273 grass
  { "BLANAS", 275, 30, R_EVO, 0x3C49, 70, 70, 40, 60, 60, 40, 2, T_GRASS, T_DARK },  // 274 grass/dark
  { "TENGULIST", 0, 0, R_EVO, 0x3C49, 90, 100, 60, 80, 90, 60, 2, T_GRASS, T_DARK },  // 275 grass/dark
  { "SCHWALBINI", 277, 22, R_COMUN, 0x8C4D, 40, 55, 30, 85, 30, 30, 0, T_NORMAL, T_FLYING },  // 276 normal/flying
  { "SCHWALBOSS", 0, 0, R_EVO, 0x8C4D, 60, 85, 60, 125, 75, 50, 0, T_NORMAL, T_FLYING },  // 277 normal/flying
  { "WINGULL", 279, 25, R_COMUN, 0x4C98, 40, 30, 30, 85, 55, 30, 1, T_WATER, T_FLYING },  // 278 water/flying
  { "PELIPPER", 0, 0, R_EVO, 0x4C98, 60, 50, 100, 65, 95, 70, 1, T_WATER, T_FLYING },  // 279 water/flying
  { "TRASLA", 281, 20, R_COMUN, 0xD28F, 28, 25, 25, 40, 45, 35, 0, T_PSYCHIC, T_FAIRY },  // 280 psychic/fairy
  { "KIRLIA", 282, 30, R_EVO, 0xD28F, 38, 35, 35, 50, 65, 55, 0, T_PSYCHIC, T_FAIRY },  // 281 psychic/fairy
  { "GUARDEVOIR", 0, 0, R_EVO, 0xD28F, 68, 65, 65, 80, 125, 115, 0, T_PSYCHIC, T_FAIRY },  // 282 psychic/fairy
  { "GEHWEIHER", 284, 22, R_COMUN, 0x7CC4, 40, 30, 32, 65, 50, 52, 2, T_BUG, T_WATER },  // 283 bug/water
  { "MASKEREGEN", 0, 0, R_EVO, 0x7CC4, 70, 60, 62, 80, 100, 82, 2, T_BUG, T_FLYING },  // 284 bug/flying
  { "KNILZ", 286, 23, R_COMUN, 0x3C49, 60, 40, 60, 35, 40, 60, 2, T_GRASS, T_NONE },  // 285 grass
  { "KAPILZ", 0, 0, R_EVO, 0x3C49, 60, 130, 80, 70, 60, 60, 2, T_GRASS, T_FIGHTING },  // 286 grass/fighting
  { "BUMMELZ", 288, 18, R_COMUN, 0x8C4D, 60, 60, 60, 30, 35, 35, 0, T_NORMAL, T_NONE },  // 287 normal
  { "MUNTIER", 289, 36, R_EVO, 0x8C4D, 80, 80, 80, 90, 55, 55, 0, T_NORMAL, T_NONE },  // 288 normal
  { "LETARKING", 0, 0, R_EVO, 0x8C4D, 150, 160, 100, 100, 95, 65, 0, T_NORMAL, T_NONE },  // 289 normal
  { "NINCADA", 291, 20, R_COMUN, 0x7CC4, 31, 45, 90, 40, 30, 30, 2, T_BUG, T_GROUND },  // 290 bug/ground
  { "NINJASK", 0, 0, R_EVO, 0x7CC4, 61, 90, 45, 160, 50, 50, 2, T_BUG, T_FLYING },  // 291 bug/flying
  { "NINJATOM", 0, 0, R_RARO, 0x7CC4, 1, 90, 45, 40, 30, 30, 2, T_BUG, T_GHOST },  // 292 bug/ghost
  { "FLURMEL", 294, 20, R_COMUN, 0x8C4D, 64, 51, 23, 28, 51, 23, 0, T_NORMAL, T_NONE },  // 293 normal
  { "KRAKEELO", 295, 40, R_EVO, 0x8C4D, 84, 71, 43, 48, 71, 43, 0, T_NORMAL, T_NONE },  // 294 normal
  { "KRAWUMMS", 0, 0, R_EVO, 0x8C4D, 104, 91, 63, 68, 91, 73, 0, T_NORMAL, T_NONE },  // 295 normal
  { "MAKUHITA", 297, 24, R_COMUN, 0xA2A5, 72, 60, 30, 25, 20, 30, 0, T_FIGHTING, T_NONE },  // 296 fighting
  { "HARIYAMA", 0, 0, R_EVO, 0xA2A5, 144, 120, 60, 50, 40, 60, 0, T_FIGHTING, T_NONE },  // 297 fighting
  { "AZURILL", 183, 25, R_COMUN, 0x8C4D, 50, 20, 40, 20, 20, 40, 0, T_NORMAL, T_FAIRY },  // 298 normal/fairy
  { "NASGNET", 476, 30, R_COMUN, 0x9407, 30, 45, 135, 30, 45, 90, 4, T_ROCK, T_NONE },  // 299 rock
  { "ENECO", 301, 30, R_COMUN, 0x8C4D, 50, 45, 45, 50, 35, 35, 0, T_NORMAL, T_NONE },  // 300 normal
  { "ENEKORO", 0, 0, R_EVO, 0x8C4D, 70, 65, 65, 90, 55, 55, 0, T_NORMAL, T_NONE },  // 301 normal
  { "ZOBIRIS", 0, 0, R_RARO, 0x5A47, 50, 75, 75, 50, 65, 65, 2, T_DARK, T_GHOST },  // 302 dark/ghost
  { "FLUNKIFER", 0, 0, R_RARO, 0x6BF1, 50, 85, 85, 50, 55, 55, 4, T_STEEL, T_FAIRY },  // 303 steel/fairy
  { "STOLLUNIOR", 305, 32, R_COMUN, 0x6BF1, 50, 70, 100, 30, 40, 40, 4, T_STEEL, T_ROCK },  // 304 steel/rock
  { "STOLLRAK", 306, 42, R_EVO, 0x6BF1, 60, 90, 140, 40, 50, 50, 4, T_STEEL, T_ROCK },  // 305 steel/rock
  { "STOLLOSS", 0, 0, R_EVO, 0x6BF1, 70, 110, 180, 50, 60, 60, 4, T_STEEL, T_ROCK },  // 306 steel/rock
  { "MEDITIE", 308, 37, R_COMUN, 0xA2A5, 30, 40, 55, 60, 40, 55, 0, T_FIGHTING, T_PSYCHIC },  // 307 fighting/psychic
  { "MEDITALIS", 0, 0, R_EVO, 0xA2A5, 60, 60, 75, 80, 60, 75, 0, T_FIGHTING, T_PSYCHIC },  // 308 fighting/psychic
  { "FRIZELBLIZ", 310, 26, R_COMUN, 0xBCA1, 40, 45, 40, 65, 65, 40, 0, T_ELECTRIC, T_NONE },  // 309 electric
  { "VOLTENSO", 0, 0, R_EVO, 0xBCA1, 70, 75, 60, 105, 105, 60, 0, T_ELECTRIC, T_NONE },  // 310 electric
  { "PLUSLE", 0, 0, R_COMUN, 0xBCA1, 60, 50, 40, 95, 85, 75, 0, T_ELECTRIC, T_NONE },  // 311 electric
  { "MINUN", 0, 0, R_COMUN, 0xBCA1, 60, 40, 50, 95, 75, 85, 0, T_ELECTRIC, T_NONE },  // 312 electric
  { "VOLBEAT", 0, 0, R_COMUN, 0x7CC4, 65, 73, 75, 85, 47, 85, 2, T_BUG, T_NONE },  // 313 bug
  { "ILLUMISE", 0, 0, R_COMUN, 0x7CC4, 65, 47, 75, 85, 73, 85, 2, T_BUG, T_NONE },  // 314 bug
  { "ROSELIA", 407, 30, R_EVO, 0x3C49, 50, 60, 45, 65, 100, 80, 2, T_GRASS, T_POISON },  // 315 grass/poison
  { "SCHLUPPUCK", 317, 26, R_COMUN, 0x8A73, 70, 43, 53, 40, 43, 53, 0, T_POISON, T_NONE },  // 316 poison
  { "SCHLUKWECH", 0, 0, R_EVO, 0x8A73, 100, 73, 83, 55, 73, 83, 0, T_POISON, T_NONE },  // 317 poison
  { "KANIVANHA", 319, 30, R_COMUN, 0x4C98, 45, 90, 20, 65, 65, 20, 1, T_WATER, T_DARK },  // 318 water/dark
  { "TOHAIDO", 0, 0, R_EVO, 0x4C98, 70, 120, 40, 95, 95, 40, 1, T_WATER, T_DARK },  // 319 water/dark
  { "WAILMER", 321, 40, R_COMUN, 0x4C98, 130, 70, 35, 60, 70, 35, 1, T_WATER, T_NONE },  // 320 water
  { "WAILORD", 0, 0, R_EVO, 0x4C98, 170, 90, 45, 60, 90, 45, 1, T_WATER, T_NONE },  // 321 water
  { "CAMAUB", 323, 33, R_COMUN, 0xEA87, 60, 60, 40, 35, 65, 45, 3, T_FIRE, T_GROUND },  // 322 fire/ground
  { "CAMERUPT", 0, 0, R_EVO, 0xEA87, 70, 100, 70, 40, 105, 75, 3, T_FIRE, T_GROUND },  // 323 fire/ground
  { "QURTEL", 0, 0, R_COMUN, 0xEA87, 70, 85, 140, 20, 85, 70, 3, T_FIRE, T_NONE },  // 324 fire
  { "SPOINK", 326, 32, R_COMUN, 0xD28F, 60, 25, 35, 60, 70, 80, 0, T_PSYCHIC, T_NONE },  // 325 psychic
  { "GROINK", 0, 0, R_EVO, 0xD28F, 80, 45, 65, 80, 90, 110, 0, T_PSYCHIC, T_NONE },  // 326 psychic
  { "PANDIR", 0, 0, R_COMUN, 0x8C4D, 60, 60, 60, 60, 60, 60, 0, T_NORMAL, T_NONE },  // 327 normal
  { "KNACKLION", 329, 35, R_COMUN, 0xB447, 45, 100, 45, 10, 45, 45, 4, T_GROUND, T_NONE },  // 328 ground
  { "VIBRAVA", 330, 45, R_EVO, 0xB447, 50, 70, 50, 70, 50, 50, 4, T_GROUND, T_DRAGON },  // 329 ground/dragon
  { "LIBELLDRA", 0, 0, R_EVO, 0xB447, 80, 100, 80, 100, 80, 80, 4, T_GROUND, T_DRAGON },  // 330 ground/dragon
  { "TUSKA", 332, 32, R_COMUN, 0x3C49, 50, 85, 40, 35, 85, 40, 2, T_GRASS, T_NONE },  // 331 grass
  { "NOKTUSKA", 0, 0, R_EVO, 0x3C49, 70, 115, 60, 55, 115, 60, 2, T_GRASS, T_DARK },  // 332 grass/dark
  { "WABLU", 334, 35, R_COMUN, 0x8C4D, 45, 40, 60, 50, 40, 75, 0, T_NORMAL, T_FLYING },  // 333 normal/flying
  { "ALTARIA", 0, 0, R_EVO, 0x5A98, 75, 70, 90, 80, 70, 105, 1, T_DRAGON, T_FLYING },  // 334 dragon/flying
  { "SENGO", 0, 0, R_COMUN, 0x8C4D, 73, 115, 60, 90, 60, 60, 0, T_NORMAL, T_NONE },  // 335 normal
  { "VIPITIS", 0, 0, R_COMUN, 0x8A73, 73, 100, 60, 65, 100, 60, 0, T_POISON, T_NONE },  // 336 poison
  { "LUNASTEIN", 0, 0, R_RARO, 0x9407, 90, 55, 65, 70, 95, 85, 4, T_ROCK, T_PSYCHIC },  // 337 rock/psychic
  { "SONNFEL", 0, 0, R_RARO, 0x9407, 90, 95, 85, 70, 55, 65, 4, T_ROCK, T_PSYCHIC },  // 338 rock/psychic
  { "SCHMERBE", 340, 30, R_COMUN, 0x4C98, 50, 48, 43, 60, 46, 41, 1, T_WATER, T_GROUND },  // 339 water/ground
  { "WELSAR", 0, 0, R_EVO, 0x4C98, 110, 78, 73, 60, 76, 71, 1, T_WATER, T_GROUND },  // 340 water/ground
  { "KREBSCORPS", 342, 30, R_COMUN, 0x4C98, 43, 80, 65, 35, 50, 35, 1, T_WATER, T_NONE },  // 341 water
  { "KREBUTACK", 0, 0, R_EVO, 0x4C98, 63, 120, 85, 55, 90, 55, 1, T_WATER, T_DARK },  // 342 water/dark
  { "PUPPANCE", 344, 36, R_COMUN, 0xB447, 40, 40, 55, 55, 40, 70, 4, T_GROUND, T_PSYCHIC },  // 343 ground/psychic
  { "LEPUMENTAS", 0, 0, R_EVO, 0xB447, 60, 70, 105, 75, 70, 120, 4, T_GROUND, T_PSYCHIC },  // 344 ground/psychic
  { "LILIEP", 346, 40, R_RARO, 0x9407, 66, 41, 77, 23, 61, 87, 4, T_ROCK, T_GRASS },  // 345 rock/grass
  { "WIELIE", 0, 0, R_EVO, 0x9407, 86, 81, 97, 43, 81, 107, 4, T_ROCK, T_GRASS },  // 346 rock/grass
  { "ANORITH", 348, 40, R_RARO, 0x9407, 45, 95, 50, 75, 40, 50, 4, T_ROCK, T_BUG },  // 347 rock/bug
  { "ARMALDO", 0, 0, R_EVO, 0x9407, 75, 125, 100, 45, 70, 80, 4, T_ROCK, T_BUG },  // 348 rock/bug
  { "BARSCHWA", 350, 40, R_COMUN, 0x4C98, 20, 15, 20, 80, 10, 55, 1, T_WATER, T_NONE },  // 349 water
  { "MILOTIC", 0, 0, R_EVO, 0x4C98, 95, 60, 79, 81, 100, 125, 1, T_WATER, T_NONE },  // 350 water
  { "FORMEO", 0, 0, R_RARO, 0x8C4D, 70, 70, 70, 70, 70, 70, 0, T_NORMAL, T_NONE },  // 351 normal
  { "KECLEON", 0, 0, R_COMUN, 0x8C4D, 60, 90, 70, 40, 60, 120, 0, T_NORMAL, T_NONE },  // 352 normal
  { "SHUPPET", 354, 37, R_COMUN, 0x6AD3, 44, 75, 35, 45, 63, 33, 0, T_GHOST, T_NONE },  // 353 ghost
  { "BANETTE", 0, 0, R_EVO, 0x6AD3, 64, 115, 65, 65, 83, 63, 0, T_GHOST, T_NONE },  // 354 ghost
  { "ZWIRRLICHT", 356, 37, R_COMUN, 0x6AD3, 20, 40, 90, 25, 30, 90, 0, T_GHOST, T_NONE },  // 355 ghost
  { "ZWIRRKLOP", 477, 40, R_EVO, 0x6AD3, 40, 70, 130, 25, 60, 130, 0, T_GHOST, T_NONE },  // 356 ghost
  { "TROPIUS", 0, 0, R_COMUN, 0x3C49, 99, 68, 83, 51, 72, 87, 2, T_GRASS, T_FLYING },  // 357 grass/flying
  { "PALIMPALIM", 0, 0, R_EVO, 0xD28F, 75, 50, 80, 65, 95, 90, 0, T_PSYCHIC, T_NONE },  // 358 psychic
  { "ABSOL", 0, 0, R_RARO, 0x5A47, 65, 130, 60, 75, 75, 60, 2, T_DARK, T_NONE },  // 359 dark
  { "ISSO", 202, 15, R_COMUN, 0xD28F, 95, 23, 48, 23, 23, 48, 0, T_PSYCHIC, T_NONE },  // 360 psychic
  { "SCHNEPPKE", 362, 42, R_COMUN, 0x4DB8, 50, 50, 50, 50, 50, 50, 5, T_ICE, T_NONE },  // 361 ice
  { "FIRNONTOR", 0, 0, R_EVO, 0x4DB8, 80, 80, 80, 80, 80, 80, 5, T_ICE, T_NONE },  // 362 ice
  { "SEEMOPS", 364, 32, R_COMUN, 0x4DB8, 70, 40, 50, 25, 55, 50, 5, T_ICE, T_WATER },  // 363 ice/water
  { "SEEJONG", 365, 44, R_EVO, 0x4DB8, 90, 60, 70, 45, 75, 70, 5, T_ICE, T_WATER },  // 364 ice/water
  { "WALRAISA", 0, 0, R_EVO, 0x4DB8, 110, 80, 90, 65, 95, 90, 5, T_ICE, T_WATER },  // 365 ice/water
  { "PERLU", 367, 40, R_COMUN, 0x4C98, 35, 64, 85, 32, 74, 55, 1, T_WATER, T_NONE },  // 366 water
  { "AALABYSS", 0, 0, R_EVO, 0x4C98, 55, 104, 105, 52, 94, 75, 1, T_WATER, T_NONE },  // 367 water
  { "SAGANABYSS", 0, 0, R_COMUN, 0x4C98, 55, 84, 105, 52, 114, 75, 1, T_WATER, T_NONE },  // 368 water
  { "RELICANTH", 0, 0, R_RARO, 0x4C98, 100, 90, 130, 55, 45, 65, 1, T_WATER, T_ROCK },  // 369 water/rock
  { "LIEBISKUS", 0, 0, R_COMUN, 0x4C98, 43, 30, 55, 97, 40, 65, 1, T_WATER, T_NONE },  // 370 water
  { "KINDWURM", 372, 30, R_RARO, 0x5A98, 45, 75, 60, 50, 40, 30, 1, T_DRAGON, T_NONE },  // 371 dragon
  { "DRASCHEL", 373, 50, R_EVO, 0x5A98, 65, 95, 100, 50, 60, 50, 1, T_DRAGON, T_NONE },  // 372 dragon
  { "BRUTALANDA", 0, 0, R_EVO, 0x5A98, 95, 135, 80, 100, 110, 80, 1, T_DRAGON, T_FLYING },  // 373 dragon/flying
  { "TANHEL", 375, 20, R_RARO, 0x6BF1, 40, 55, 80, 30, 35, 60, 4, T_STEEL, T_PSYCHIC },  // 374 steel/psychic
  { "METANG", 376, 45, R_EVO, 0x6BF1, 60, 75, 100, 50, 55, 80, 4, T_STEEL, T_PSYCHIC },  // 375 steel/psychic
  { "METAGROSS", 0, 0, R_EVO, 0x6BF1, 80, 135, 130, 70, 95, 90, 4, T_STEEL, T_PSYCHIC },  // 376 steel/psychic
  { "REGIROCK", 0, 0, R_LEGENDARIO, 0x9407, 80, 100, 200, 50, 50, 100, 4, T_ROCK, T_NONE },  // 377 rock
  { "REGICE", 0, 0, R_LEGENDARIO, 0x4DB8, 80, 50, 100, 50, 100, 200, 5, T_ICE, T_NONE },  // 378 ice
  { "REGISTEEL", 0, 0, R_LEGENDARIO, 0x6BF1, 80, 75, 150, 50, 75, 150, 4, T_STEEL, T_NONE },  // 379 steel
  { "LATIAS", 0, 0, R_LEGENDARIO, 0x5A98, 80, 80, 90, 110, 110, 130, 1, T_DRAGON, T_PSYCHIC },  // 380 dragon/psychic
  { "LATIOS", 0, 0, R_LEGENDARIO, 0x5A98, 80, 90, 80, 110, 130, 110, 1, T_DRAGON, T_PSYCHIC },  // 381 dragon/psychic
  { "KYOGRE", 0, 0, R_LEGENDARIO, 0x4C98, 100, 100, 90, 90, 150, 140, 1, T_WATER, T_NONE },  // 382 water
  { "GROUDON", 0, 0, R_LEGENDARIO, 0xB447, 100, 150, 140, 90, 100, 90, 4, T_GROUND, T_NONE },  // 383 ground
  { "RAYQUAZA", 0, 0, R_LEGENDARIO, 0x5A98, 105, 150, 90, 95, 150, 90, 1, T_DRAGON, T_FLYING },  // 384 dragon/flying
  { "JIRACHI", 0, 0, R_LEGENDARIO, 0x6BF1, 100, 100, 100, 100, 100, 100, 4, T_STEEL, T_PSYCHIC },  // 385 steel/psychic
  { "DEOXYS", 0, 0, R_LEGENDARIO, 0xD28F, 50, 150, 50, 150, 150, 50, 0, T_PSYCHIC, T_NONE },  // 386 psychic
  { "CHELAST", 388, 18, R_RARO, 0x3C49, 55, 68, 64, 31, 45, 55, 2, T_GRASS, T_NONE },  // 387 grass
  { "CHELCARAIN", 389, 32, R_EVO, 0x3C49, 75, 89, 85, 36, 55, 65, 2, T_GRASS, T_NONE },  // 388 grass
  { "CHELTERRAR", 0, 0, R_EVO, 0x3C49, 95, 109, 105, 56, 75, 85, 2, T_GRASS, T_GROUND },  // 389 grass/ground
  { "PANFLAM", 391, 14, R_RARO, 0xEA87, 44, 58, 44, 61, 58, 44, 3, T_FIRE, T_NONE },  // 390 fire
  { "PANPYRO", 392, 36, R_EVO, 0xEA87, 64, 78, 52, 81, 78, 52, 3, T_FIRE, T_FIGHTING },  // 391 fire/fighting
  { "PANFERNO", 0, 0, R_EVO, 0xEA87, 76, 104, 71, 108, 104, 71, 3, T_FIRE, T_FIGHTING },  // 392 fire/fighting
  { "PLINFA", 394, 16, R_RARO, 0x4C98, 53, 51, 53, 40, 61, 56, 1, T_WATER, T_NONE },  // 393 water
  { "PLIPRIN", 395, 36, R_EVO, 0x4C98, 64, 66, 68, 50, 81, 76, 1, T_WATER, T_NONE },  // 394 water
  { "IMPOLEON", 0, 0, R_EVO, 0x4C98, 84, 86, 88, 60, 111, 101, 1, T_WATER, T_STEEL },  // 395 water/steel
  { "STARALILI", 397, 14, R_COMUN, 0x8C4D, 40, 55, 30, 60, 30, 30, 0, T_NORMAL, T_FLYING },  // 396 normal/flying
  { "STARAVIA", 398, 34, R_EVO, 0x8C4D, 55, 75, 50, 80, 40, 40, 0, T_NORMAL, T_FLYING },  // 397 normal/flying
  { "STARAPTOR", 0, 0, R_EVO, 0x8C4D, 85, 120, 70, 100, 50, 60, 0, T_NORMAL, T_FLYING },  // 398 normal/flying
  { "BIDIZA", 400, 15, R_COMUN, 0x8C4D, 59, 45, 40, 31, 35, 40, 0, T_NORMAL, T_NONE },  // 399 normal
  { "BIDIFAS", 0, 0, R_EVO, 0x8C4D, 79, 85, 60, 71, 55, 60, 0, T_NORMAL, T_WATER },  // 400 normal/water
  { "ZIRPURZE", 402, 10, R_COMUN, 0x7CC4, 37, 25, 41, 25, 25, 41, 2, T_BUG, T_NONE },  // 401 bug
  { "ZIRPEISE", 0, 0, R_EVO, 0x7CC4, 77, 85, 51, 65, 55, 51, 2, T_BUG, T_NONE },  // 402 bug
  { "SHEINUX", 404, 15, R_COMUN, 0xBCA1, 45, 65, 34, 45, 40, 34, 0, T_ELECTRIC, T_NONE },  // 403 electric
  { "LUXIO", 405, 30, R_EVO, 0xBCA1, 60, 85, 49, 60, 60, 49, 0, T_ELECTRIC, T_NONE },  // 404 electric
  { "LUXTRA", 0, 0, R_EVO, 0xBCA1, 80, 120, 79, 70, 95, 79, 0, T_ELECTRIC, T_NONE },  // 405 electric
  { "KNOSPI", 315, 25, R_COMUN, 0x3C49, 40, 30, 35, 55, 50, 70, 2, T_GRASS, T_POISON },  // 406 grass/poison
  { "ROSERADE", 0, 0, R_EVO, 0x3C49, 60, 70, 65, 90, 125, 105, 2, T_GRASS, T_POISON },  // 407 grass/poison
  { "KOKNODON", 409, 30, R_RARO, 0x9407, 67, 125, 40, 58, 30, 30, 4, T_ROCK, T_NONE },  // 408 rock
  { "RAMEIDON", 0, 0, R_EVO, 0x9407, 97, 165, 60, 58, 65, 50, 4, T_ROCK, T_NONE },  // 409 rock
  { "SCHILTERUS", 411, 30, R_RARO, 0x9407, 30, 42, 118, 30, 42, 88, 4, T_ROCK, T_STEEL },  // 410 rock/steel
  { "BOLLTERUS", 0, 0, R_EVO, 0x9407, 60, 52, 168, 30, 47, 138, 4, T_ROCK, T_STEEL },  // 411 rock/steel
  { "BURMY", 413, 20, R_COMUN, 0x7CC4, 40, 29, 45, 36, 29, 45, 2, T_BUG, T_NONE },  // 412 bug
  { "BURMADAME", 0, 0, R_EVO, 0x7CC4, 60, 59, 85, 36, 79, 105, 2, T_BUG, T_GRASS },  // 413 bug/grass
  { "MOTERPEL", 0, 0, R_RARO, 0x7CC4, 70, 94, 50, 66, 94, 50, 2, T_BUG, T_FLYING },  // 414 bug/flying
  { "WADRIBIE", 416, 21, R_COMUN, 0x7CC4, 30, 30, 42, 70, 30, 42, 2, T_BUG, T_FLYING },  // 415 bug/flying
  { "HONWEISEL", 0, 0, R_EVO, 0x7CC4, 70, 80, 102, 40, 80, 102, 2, T_BUG, T_FLYING },  // 416 bug/flying
  { "PACHIRISU", 0, 0, R_COMUN, 0xBCA1, 60, 45, 70, 95, 45, 90, 0, T_ELECTRIC, T_NONE },  // 417 electric
  { "BAMELIN", 419, 26, R_COMUN, 0x4C98, 55, 65, 35, 85, 60, 30, 1, T_WATER, T_NONE },  // 418 water
  { "BOJELIN", 0, 0, R_EVO, 0x4C98, 85, 105, 55, 115, 85, 50, 1, T_WATER, T_NONE },  // 419 water
  { "KIKUGI", 421, 25, R_COMUN, 0x3C49, 45, 35, 45, 35, 62, 53, 2, T_GRASS, T_NONE },  // 420 grass
  { "KINOSO", 0, 0, R_EVO, 0x3C49, 70, 60, 70, 85, 87, 78, 2, T_GRASS, T_NONE },  // 421 grass
  { "SCHALELLOS", 423, 30, R_COMUN, 0x4C98, 76, 48, 48, 34, 57, 62, 1, T_WATER, T_NONE },  // 422 water
  { "GASTRODON", 0, 0, R_EVO, 0x4C98, 111, 83, 68, 39, 92, 82, 1, T_WATER, T_GROUND },  // 423 water/ground
  { "AMBIDIFFEL", 0, 0, R_EVO, 0x8C4D, 75, 100, 66, 115, 60, 66, 0, T_NORMAL, T_NONE },  // 424 normal
  { "DRIFTLON", 426, 28, R_COMUN, 0x6AD3, 90, 50, 34, 70, 60, 44, 0, T_GHOST, T_FLYING },  // 425 ghost/flying
  { "DRIFZEPELI", 0, 0, R_EVO, 0x6AD3, 150, 80, 44, 80, 90, 54, 0, T_GHOST, T_FLYING },  // 426 ghost/flying
  { "HASPIROR", 428, 25, R_COMUN, 0x8C4D, 55, 66, 44, 85, 44, 56, 0, T_NORMAL, T_NONE },  // 427 normal
  { "SCHLAPOR", 0, 0, R_EVO, 0x8C4D, 65, 76, 84, 105, 54, 96, 0, T_NORMAL, T_NONE },  // 428 normal
  { "TRAUNMAGIL", 0, 0, R_EVO, 0x6AD3, 60, 60, 60, 105, 105, 105, 0, T_GHOST, T_NONE },  // 429 ghost
  { "KRAMSHEF", 0, 0, R_EVO, 0x5A47, 100, 125, 52, 71, 105, 52, 2, T_DARK, T_FLYING },  // 430 dark/flying
  { "CHARMIAN", 432, 38, R_COMUN, 0x8C4D, 49, 55, 42, 85, 42, 37, 0, T_NORMAL, T_NONE },  // 431 normal
  { "SHNURGARST", 0, 0, R_EVO, 0x8C4D, 71, 82, 64, 112, 64, 59, 0, T_NORMAL, T_NONE },  // 432 normal
  { "KLINGPLIM", 358, 25, R_COMUN, 0xD28F, 45, 30, 50, 45, 65, 50, 0, T_PSYCHIC, T_NONE },  // 433 psychic
  { "SKUNKAPUH", 435, 34, R_COMUN, 0x8A73, 63, 63, 47, 74, 41, 41, 0, T_POISON, T_DARK },  // 434 poison/dark
  { "SKUNTANK", 0, 0, R_EVO, 0x8A73, 103, 93, 67, 84, 71, 61, 0, T_POISON, T_DARK },  // 435 poison/dark
  { "BRONZEL", 437, 33, R_COMUN, 0x6BF1, 57, 24, 86, 23, 24, 86, 4, T_STEEL, T_PSYCHIC },  // 436 steel/psychic
  { "BRONZONG", 0, 0, R_EVO, 0x6BF1, 67, 89, 116, 33, 79, 116, 4, T_STEEL, T_PSYCHIC },  // 437 steel/psychic
  { "MOBAI", 185, 30, R_COMUN, 0x9407, 50, 80, 95, 10, 10, 45, 4, T_ROCK, T_NONE },  // 438 rock
  { "PANTIMIMI", 122, 30, R_COMUN, 0xD28F, 20, 25, 45, 60, 70, 90, 0, T_PSYCHIC, T_FAIRY },  // 439 psychic/fairy
  { "WONNEIRA", 113, 30, R_COMUN, 0x8C4D, 100, 5, 5, 30, 15, 65, 0, T_NORMAL, T_NONE },  // 440 normal
  { "PLAUDAGEI", 0, 0, R_RARO, 0x8C4D, 76, 65, 45, 91, 92, 42, 0, T_NORMAL, T_FLYING },  // 441 normal/flying
  { "KRYPPUK", 0, 0, R_COMUN, 0x6AD3, 50, 92, 108, 35, 92, 108, 0, T_GHOST, T_DARK },  // 442 ghost/dark
  { "KAUMALAT", 444, 24, R_RARO, 0x5A98, 58, 70, 45, 42, 40, 45, 1, T_DRAGON, T_GROUND },  // 443 dragon/ground
  { "KNARKSEL", 445, 48, R_EVO, 0x5A98, 68, 90, 65, 82, 50, 55, 1, T_DRAGON, T_GROUND },  // 444 dragon/ground
  { "KNAKRACK", 0, 0, R_EVO, 0x5A98, 108, 130, 95, 102, 80, 85, 1, T_DRAGON, T_GROUND },  // 445 dragon/ground
  { "MAMPFAXO", 143, 25, R_COMUN, 0x8C4D, 135, 85, 40, 5, 40, 85, 0, T_NORMAL, T_NONE },  // 446 normal
  { "RIOLU", 448, 25, R_COMUN, 0xA2A5, 40, 70, 40, 60, 35, 40, 0, T_FIGHTING, T_NONE },  // 447 fighting
  { "LUCARIO", 0, 0, R_EVO, 0xA2A5, 70, 110, 70, 90, 115, 70, 0, T_FIGHTING, T_STEEL },  // 448 fighting/steel
  { "HIPPOPOTAS", 450, 34, R_COMUN, 0xB447, 68, 72, 78, 32, 38, 42, 4, T_GROUND, T_NONE },  // 449 ground
  { "HIPPOTERUS", 0, 0, R_EVO, 0xB447, 108, 112, 118, 47, 68, 72, 4, T_GROUND, T_NONE },  // 450 ground
  { "PIONSKORA", 452, 40, R_COMUN, 0x8A73, 40, 50, 90, 65, 30, 55, 0, T_POISON, T_BUG },  // 451 poison/bug
  { "PIONDRAGI", 0, 0, R_EVO, 0x8A73, 70, 90, 110, 95, 60, 75, 0, T_POISON, T_DARK },  // 452 poison/dark
  { "GLIBUNKEL", 454, 37, R_COMUN, 0x8A73, 48, 61, 40, 50, 61, 40, 0, T_POISON, T_FIGHTING },  // 453 poison/fighting
  { "TOXIQUAK", 0, 0, R_EVO, 0x8A73, 83, 106, 65, 85, 86, 65, 0, T_POISON, T_FIGHTING },  // 454 poison/fighting
  { "VENUFLIBIS", 0, 0, R_COMUN, 0x3C49, 74, 100, 72, 46, 90, 72, 2, T_GRASS, T_NONE },  // 455 grass
  { "FINNEON", 457, 31, R_COMUN, 0x4C98, 49, 49, 56, 66, 49, 61, 1, T_WATER, T_NONE },  // 456 water
  { "LUMINEON", 0, 0, R_EVO, 0x4C98, 69, 69, 76, 91, 69, 86, 1, T_WATER, T_NONE },  // 457 water
  { "MANTIRPS", 226, 30, R_RARO, 0x4C98, 45, 20, 50, 50, 60, 120, 1, T_WATER, T_FLYING },  // 458 water/flying
  { "SHNEBEDECK", 460, 40, R_COMUN, 0x3C49, 60, 62, 50, 40, 62, 60, 2, T_GRASS, T_ICE },  // 459 grass/ice
  { "REXBLISAR", 0, 0, R_EVO, 0x3C49, 90, 92, 75, 60, 92, 85, 2, T_GRASS, T_ICE },  // 460 grass/ice
  { "SNIBUNNA", 0, 0, R_EVO, 0x5A47, 70, 120, 65, 125, 45, 85, 2, T_DARK, T_ICE },  // 461 dark/ice
  { "MAGNEZONE", 0, 0, R_EVO, 0xBCA1, 70, 70, 115, 60, 130, 90, 0, T_ELECTRIC, T_STEEL },  // 462 electric/steel
  { "SCHLURPLEK", 0, 0, R_EVO, 0x8C4D, 110, 85, 95, 50, 80, 95, 0, T_NORMAL, T_NONE },  // 463 normal
  { "RIHORNIOR", 0, 0, R_EVO, 0xB447, 115, 140, 130, 40, 55, 55, 4, T_GROUND, T_ROCK },  // 464 ground/rock
  { "TANGOLOSS", 0, 0, R_EVO, 0x3C49, 100, 100, 125, 50, 110, 50, 2, T_GRASS, T_NONE },  // 465 grass
  { "ELEVOLTEK", 0, 0, R_EVO, 0xBCA1, 75, 123, 67, 95, 95, 85, 0, T_ELECTRIC, T_NONE },  // 466 electric
  { "MAGBRANT", 0, 0, R_EVO, 0xEA87, 75, 95, 67, 83, 125, 95, 3, T_FIRE, T_NONE },  // 467 fire
  { "TOGEKISS", 0, 0, R_EVO, 0xC333, 85, 50, 95, 80, 120, 115, 0, T_FAIRY, T_FLYING },  // 468 fairy/flying
  { "YANMEGA", 0, 0, R_EVO, 0x7CC4, 86, 76, 86, 95, 116, 56, 2, T_BUG, T_FLYING },  // 469 bug/flying
  { "FOLIPURBA", 0, 0, R_EVO, 0x3C49, 65, 110, 130, 95, 60, 65, 2, T_GRASS, T_NONE },  // 470 grass
  { "GLAZIOLA", 0, 0, R_EVO, 0x4DB8, 65, 60, 110, 65, 130, 95, 5, T_ICE, T_NONE },  // 471 ice
  { "SKORGRO", 0, 0, R_EVO, 0xB447, 75, 95, 125, 95, 45, 75, 4, T_GROUND, T_FLYING },  // 472 ground/flying
  { "MAMUTEL", 0, 0, R_EVO, 0x4DB8, 110, 130, 80, 80, 70, 60, 5, T_ICE, T_GROUND },  // 473 ice/ground
  { "PORYGON-Z", 0, 0, R_EVO, 0x8C4D, 85, 80, 70, 90, 135, 75, 0, T_NORMAL, T_NONE },  // 474 normal
  { "GALAGLADI", 0, 0, R_RARO, 0xD28F, 68, 125, 65, 80, 65, 115, 0, T_PSYCHIC, T_FIGHTING },  // 475 psychic/fighting
  { "VOLUMINAS", 0, 0, R_EVO, 0x9407, 60, 55, 145, 40, 75, 150, 4, T_ROCK, T_STEEL },  // 476 rock/steel
  { "ZWIRRFINST", 0, 0, R_EVO, 0x6AD3, 45, 100, 135, 45, 65, 135, 0, T_GHOST, T_NONE },  // 477 ghost
  { "FROSDEDJE", 0, 0, R_COMUN, 0x4DB8, 70, 80, 70, 110, 80, 70, 5, T_ICE, T_GHOST },  // 478 ice/ghost
  { "ROTOM", 0, 0, R_RARO, 0xBCA1, 50, 50, 77, 91, 95, 77, 0, T_ELECTRIC, T_GHOST },  // 479 electric/ghost
  { "SELFE", 0, 0, R_LEGENDARIO, 0xD28F, 75, 75, 130, 95, 75, 130, 0, T_PSYCHIC, T_NONE },  // 480 psychic
  { "VESPRIT", 0, 0, R_LEGENDARIO, 0xD28F, 80, 105, 105, 80, 105, 105, 0, T_PSYCHIC, T_NONE },  // 481 psychic
  { "TOBUTZ", 0, 0, R_LEGENDARIO, 0xD28F, 75, 125, 70, 115, 125, 70, 0, T_PSYCHIC, T_NONE },  // 482 psychic
  { "DIALGA", 0, 0, R_LEGENDARIO, 0x6BF1, 100, 120, 120, 90, 150, 100, 4, T_STEEL, T_DRAGON },  // 483 steel/dragon
  { "PALKIA", 0, 0, R_LEGENDARIO, 0x4C98, 90, 120, 100, 100, 150, 120, 1, T_WATER, T_DRAGON },  // 484 water/dragon
  { "HEATRAN", 0, 0, R_LEGENDARIO, 0xEA87, 91, 90, 106, 77, 130, 106, 3, T_FIRE, T_STEEL },  // 485 fire/steel
  { "REGIGIGAS", 0, 0, R_LEGENDARIO, 0x8C4D, 110, 160, 110, 100, 80, 110, 0, T_NORMAL, T_NONE },  // 486 normal
  { "GIRATINA", 0, 0, R_LEGENDARIO, 0x6AD3, 150, 100, 120, 90, 100, 120, 0, T_GHOST, T_DRAGON },  // 487 ghost/dragon
  { "CRESSELIA", 0, 0, R_LEGENDARIO, 0xD28F, 120, 70, 110, 85, 75, 120, 0, T_PSYCHIC, T_NONE },  // 488 psychic
  { "PHIONE", 490, 30, R_LEGENDARIO, 0x4C98, 80, 80, 80, 80, 80, 80, 1, T_WATER, T_NONE },  // 489 water
  { "MANAPHY", 0, 0, R_EVO, 0x4C98, 100, 100, 100, 100, 100, 100, 1, T_WATER, T_NONE },  // 490 water
  { "DARKRAI", 0, 0, R_LEGENDARIO, 0x5A47, 70, 90, 90, 125, 135, 90, 2, T_DARK, T_NONE },  // 491 dark
  { "SHAYMIN", 0, 0, R_LEGENDARIO, 0x3C49, 100, 100, 100, 100, 100, 100, 2, T_GRASS, T_NONE },  // 492 grass
  { "ARCEUS", 0, 0, R_LEGENDARIO, 0x8C4D, 120, 120, 120, 120, 120, 120, 0, T_NORMAL, T_NONE },  // 493 normal
  { "VICTINI", 0, 0, R_LEGENDARIO, 0xD28F, 100, 100, 100, 100, 100, 100, 0, T_PSYCHIC, T_FIRE },  // 494 psychic/fire
  { "SERPIFEU", 496, 17, R_RARO, 0x3C49, 45, 45, 55, 63, 45, 55, 2, T_GRASS, T_NONE },  // 495 grass
  { "EFOSERP", 497, 36, R_EVO, 0x3C49, 60, 60, 75, 83, 60, 75, 2, T_GRASS, T_NONE },  // 496 grass
  { "SERPIROYAL", 0, 0, R_EVO, 0x3C49, 75, 75, 95, 113, 75, 95, 2, T_GRASS, T_NONE },  // 497 grass
  { "FLOINK", 499, 17, R_RARO, 0xEA87, 65, 63, 45, 45, 45, 45, 3, T_FIRE, T_NONE },  // 498 fire
  { "FERKOKEL", 500, 36, R_EVO, 0xEA87, 90, 93, 55, 55, 70, 55, 3, T_FIRE, T_FIGHTING },  // 499 fire/fighting
  { "FLAMBIREX", 0, 0, R_EVO, 0xEA87, 110, 123, 65, 65, 100, 65, 3, T_FIRE, T_FIGHTING },  // 500 fire/fighting
  { "OTTARO", 502, 17, R_RARO, 0x4C98, 55, 55, 45, 45, 63, 45, 1, T_WATER, T_NONE },  // 501 water
  { "ZWOTTRONIN", 503, 36, R_EVO, 0x4C98, 75, 75, 60, 60, 83, 60, 1, T_WATER, T_NONE },  // 502 water
  { "ADMURAI", 0, 0, R_EVO, 0x4C98, 95, 100, 85, 70, 108, 70, 1, T_WATER, T_NONE },  // 503 water
  { "NAGELOTZ", 505, 20, R_COMUN, 0x8C4D, 45, 55, 39, 42, 35, 39, 0, T_NORMAL, T_NONE },  // 504 normal
  { "KUKMARDA", 0, 0, R_EVO, 0x8C4D, 60, 85, 69, 77, 60, 69, 0, T_NORMAL, T_NONE },  // 505 normal
  { "YORKLEFF", 507, 16, R_COMUN, 0x8C4D, 45, 60, 45, 55, 25, 45, 0, T_NORMAL, T_NONE },  // 506 normal
  { "TERRIBARK", 508, 32, R_EVO, 0x8C4D, 65, 80, 65, 60, 35, 65, 0, T_NORMAL, T_NONE },  // 507 normal
  { "BISSBARK", 0, 0, R_EVO, 0x8C4D, 85, 110, 90, 80, 45, 90, 0, T_NORMAL, T_NONE },  // 508 normal
  { "FELILOU", 510, 20, R_COMUN, 0x5A47, 41, 50, 37, 66, 50, 37, 2, T_DARK, T_NONE },  // 509 dark
  { "KLEOPARDA", 0, 0, R_EVO, 0x5A47, 64, 88, 50, 106, 88, 50, 2, T_DARK, T_NONE },  // 510 dark
  { "VEGIMAK", 512, 30, R_COMUN, 0x3C49, 50, 53, 48, 64, 53, 48, 2, T_GRASS, T_NONE },  // 511 grass
  { "VEGICHITA", 0, 0, R_EVO, 0x3C49, 75, 98, 63, 101, 98, 63, 2, T_GRASS, T_NONE },  // 512 grass
  { "GRILLMAK", 514, 30, R_COMUN, 0xEA87, 50, 53, 48, 64, 53, 48, 3, T_FIRE, T_NONE },  // 513 fire
  { "GRILLCHITA", 0, 0, R_EVO, 0xEA87, 75, 98, 63, 101, 98, 63, 3, T_FIRE, T_NONE },  // 514 fire
  { "SODAMAK", 516, 30, R_COMUN, 0x4C98, 50, 53, 48, 64, 53, 48, 1, T_WATER, T_NONE },  // 515 water
  { "SODACHITA", 0, 0, R_EVO, 0x4C98, 75, 98, 63, 101, 98, 63, 1, T_WATER, T_NONE },  // 516 water
  { "SOMNIAM", 518, 30, R_COMUN, 0xD28F, 76, 25, 45, 24, 67, 55, 0, T_PSYCHIC, T_NONE },  // 517 psychic
  { "SOMNIVORA", 0, 0, R_EVO, 0xD28F, 116, 55, 85, 29, 107, 95, 0, T_PSYCHIC, T_NONE },  // 518 psychic
  { "DUSSELGURR", 520, 21, R_COMUN, 0x8C4D, 50, 55, 50, 43, 36, 30, 0, T_NORMAL, T_FLYING },  // 519 normal/flying
  { "NAVITAUB", 521, 32, R_EVO, 0x8C4D, 62, 77, 62, 65, 50, 42, 0, T_NORMAL, T_FLYING },  // 520 normal/flying
  { "FASASNOB", 0, 0, R_EVO, 0x8C4D, 80, 115, 80, 93, 65, 55, 0, T_NORMAL, T_FLYING },  // 521 normal/flying
  { "ELEZEBA", 523, 27, R_COMUN, 0xBCA1, 45, 60, 32, 76, 50, 32, 0, T_ELECTRIC, T_NONE },  // 522 electric
  { "ZEBRITZ", 0, 0, R_EVO, 0xBCA1, 75, 100, 63, 116, 80, 63, 0, T_ELECTRIC, T_NONE },  // 523 electric
  { "KIESLING", 525, 25, R_COMUN, 0x9407, 55, 75, 85, 15, 25, 25, 4, T_ROCK, T_NONE },  // 524 rock
  { "SEDIMANTUR", 526, 40, R_EVO, 0x9407, 70, 105, 105, 20, 50, 40, 4, T_ROCK, T_NONE },  // 525 rock
  { "BROCKOLOSS", 0, 0, R_EVO, 0x9407, 85, 135, 130, 25, 60, 80, 4, T_ROCK, T_NONE },  // 526 rock
  { "FLEKNOIL", 528, 25, R_COMUN, 0xD28F, 65, 45, 43, 72, 55, 43, 0, T_PSYCHIC, T_FLYING },  // 527 psychic/flying
  { "FLETIAMO", 0, 0, R_EVO, 0xD28F, 67, 57, 55, 114, 77, 55, 0, T_PSYCHIC, T_FLYING },  // 528 psychic/flying
  { "ROTOMURF", 530, 31, R_COMUN, 0xB447, 60, 85, 40, 68, 30, 45, 4, T_GROUND, T_NONE },  // 529 ground
  { "STALOBOR", 0, 0, R_EVO, 0xB447, 110, 135, 60, 88, 50, 65, 4, T_GROUND, T_STEEL },  // 530 ground/steel
  { "OHRDOCH", 0, 0, R_COMUN, 0x8C4D, 103, 60, 86, 50, 60, 86, 0, T_NORMAL, T_NONE },  // 531 normal
  { "PRAKTIBALK", 533, 25, R_COMUN, 0xA2A5, 75, 80, 55, 35, 25, 35, 0, T_FIGHTING, T_NONE },  // 532 fighting
  { "STREPOLI", 534, 40, R_EVO, 0xA2A5, 85, 105, 85, 40, 40, 50, 0, T_FIGHTING, T_NONE },  // 533 fighting
  { "MEISTAGRIF", 0, 0, R_EVO, 0xA2A5, 105, 140, 95, 45, 55, 65, 0, T_FIGHTING, T_NONE },  // 534 fighting
  { "SCHALLQUAP", 536, 25, R_COMUN, 0x4C98, 50, 50, 40, 64, 50, 40, 1, T_WATER, T_NONE },  // 535 water
  { "MEBRANA", 537, 36, R_EVO, 0x4C98, 75, 65, 55, 69, 65, 55, 1, T_WATER, T_GROUND },  // 536 water/ground
  { "BRANAWARZ", 0, 0, R_EVO, 0x4C98, 105, 95, 75, 74, 85, 75, 1, T_WATER, T_GROUND },  // 537 water/ground
  { "JIUTESTO", 0, 0, R_RARO, 0xA2A5, 120, 100, 85, 45, 30, 85, 0, T_FIGHTING, T_NONE },  // 538 fighting
  { "KARADONIS", 0, 0, R_RARO, 0xA2A5, 75, 125, 75, 85, 30, 75, 0, T_FIGHTING, T_NONE },  // 539 fighting
  { "STRAWICKL", 541, 20, R_COMUN, 0x7CC4, 45, 53, 70, 42, 40, 60, 2, T_BUG, T_GRASS },  // 540 bug/grass
  { "FOLIKON", 542, 25, R_EVO, 0x7CC4, 55, 63, 90, 42, 50, 80, 2, T_BUG, T_GRASS },  // 541 bug/grass
  { "MATRIFOL", 0, 0, R_EVO, 0x7CC4, 75, 103, 80, 92, 70, 80, 2, T_BUG, T_GRASS },  // 542 bug/grass
  { "TOXIPED", 544, 22, R_COMUN, 0x7CC4, 30, 45, 59, 57, 30, 39, 2, T_BUG, T_POISON },  // 543 bug/poison
  { "ROLLUM", 545, 30, R_EVO, 0x7CC4, 40, 55, 99, 47, 40, 79, 2, T_BUG, T_POISON },  // 544 bug/poison
  { "CERAPENDRA", 0, 0, R_EVO, 0x7CC4, 60, 100, 89, 112, 55, 69, 2, T_BUG, T_POISON },  // 545 bug/poison
  { "WAUMBOLL", 547, 30, R_COMUN, 0x3C49, 40, 27, 60, 66, 37, 50, 2, T_GRASS, T_FAIRY },  // 546 grass/fairy
  { "ELFUN", 0, 0, R_EVO, 0x3C49, 60, 67, 85, 116, 77, 75, 2, T_GRASS, T_FAIRY },  // 547 grass/fairy
  { "LILMINIP", 549, 30, R_COMUN, 0x3C49, 45, 35, 50, 30, 70, 50, 2, T_GRASS, T_NONE },  // 548 grass
  { "DRESSELLA", 0, 0, R_EVO, 0x3C49, 70, 60, 75, 90, 110, 75, 2, T_GRASS, T_NONE },  // 549 grass
  { "BARSCHUFT", 0, 0, R_RARO, 0x4C98, 70, 92, 65, 98, 80, 55, 1, T_WATER, T_NONE },  // 550 water
  { "GANOVIL", 552, 29, R_COMUN, 0xB447, 50, 72, 35, 65, 35, 35, 4, T_GROUND, T_DARK },  // 551 ground/dark
  { "ROKKAIMAN", 553, 40, R_EVO, 0xB447, 60, 82, 45, 74, 45, 45, 4, T_GROUND, T_DARK },  // 552 ground/dark
  { "RABIGATOR", 0, 0, R_EVO, 0xB447, 95, 117, 80, 92, 65, 70, 4, T_GROUND, T_DARK },  // 553 ground/dark
  { "FLAMPION", 555, 35, R_COMUN, 0xEA87, 70, 90, 45, 50, 15, 45, 3, T_FIRE, T_NONE },  // 554 fire
  { "FLAMPIVIAN", 0, 0, R_EVO, 0xEA87, 105, 140, 55, 95, 30, 55, 3, T_FIRE, T_NONE },  // 555 fire
  { "MARACAMBA", 0, 0, R_COMUN, 0x3C49, 75, 86, 67, 60, 106, 67, 2, T_GRASS, T_NONE },  // 556 grass
  { "LITHOMITH", 558, 34, R_COMUN, 0x7CC4, 50, 65, 85, 55, 35, 35, 2, T_BUG, T_ROCK },  // 557 bug/rock
  { "CASTELLITH", 0, 0, R_EVO, 0x7CC4, 70, 105, 125, 45, 65, 75, 2, T_BUG, T_ROCK },  // 558 bug/rock
  { "ZURROKEX", 560, 39, R_COMUN, 0x5A47, 50, 75, 70, 48, 35, 70, 2, T_DARK, T_FIGHTING },  // 559 dark/fighting
  { "IROKEX", 0, 0, R_EVO, 0x5A47, 65, 90, 115, 58, 45, 115, 2, T_DARK, T_FIGHTING },  // 560 dark/fighting
  { "SYMVOLARA", 0, 0, R_RARO, 0xD28F, 72, 58, 80, 97, 103, 80, 0, T_PSYCHIC, T_FLYING },  // 561 psychic/flying
  { "MAKABAJA", 563, 34, R_COMUN, 0x6AD3, 38, 30, 85, 30, 55, 65, 0, T_GHOST, T_NONE },  // 562 ghost
  { "ECHNATOLL", 0, 0, R_EVO, 0x6AD3, 58, 50, 145, 30, 95, 105, 0, T_GHOST, T_NONE },  // 563 ghost
  { "GALAPAFLOS", 565, 37, R_RARO, 0x4C98, 54, 78, 103, 22, 53, 45, 1, T_WATER, T_ROCK },  // 564 water/rock
  { "KARIPPAS", 0, 0, R_EVO, 0x4C98, 74, 108, 133, 32, 83, 65, 1, T_WATER, T_ROCK },  // 565 water/rock
  { "FLAPTERYX", 567, 37, R_RARO, 0x9407, 55, 112, 45, 70, 74, 45, 4, T_ROCK, T_FLYING },  // 566 rock/flying
  { "AEROPTERYX", 0, 0, R_EVO, 0x9407, 75, 140, 65, 110, 112, 65, 4, T_ROCK, T_FLYING },  // 567 rock/flying
  { "UNRATUETOX", 569, 36, R_COMUN, 0x8A73, 50, 50, 62, 65, 40, 62, 0, T_POISON, T_NONE },  // 568 poison
  { "DEPONITOX", 0, 0, R_EVO, 0x8A73, 80, 95, 82, 75, 60, 82, 0, T_POISON, T_NONE },  // 569 poison
  { "ZORUA", 571, 30, R_COMUN, 0x5A47, 40, 65, 40, 65, 80, 40, 2, T_DARK, T_NONE },  // 570 dark
  { "ZOROARK", 0, 0, R_EVO, 0x5A47, 60, 105, 60, 105, 120, 60, 2, T_DARK, T_NONE },  // 571 dark
  { "PICOCHILLA", 573, 30, R_COMUN, 0x8C4D, 55, 50, 40, 75, 40, 40, 0, T_NORMAL, T_NONE },  // 572 normal
  { "CHILLABELL", 0, 0, R_EVO, 0x8C4D, 75, 95, 60, 115, 65, 60, 0, T_NORMAL, T_NONE },  // 573 normal
  { "MOLLIMORBA", 575, 32, R_COMUN, 0xD28F, 45, 30, 50, 45, 55, 65, 0, T_PSYCHIC, T_NONE },  // 574 psychic
  { "HYPNOMORBA", 576, 41, R_EVO, 0xD28F, 60, 45, 70, 55, 75, 85, 0, T_PSYCHIC, T_NONE },  // 575 psychic
  { "MORBITESSE", 0, 0, R_EVO, 0xD28F, 70, 55, 95, 65, 95, 110, 0, T_PSYCHIC, T_NONE },  // 576 psychic
  { "MONOZYTO", 578, 32, R_COMUN, 0xD28F, 45, 30, 40, 20, 105, 50, 0, T_PSYCHIC, T_NONE },  // 577 psychic
  { "MITODOS", 579, 41, R_EVO, 0xD28F, 65, 40, 50, 30, 125, 60, 0, T_PSYCHIC, T_NONE },  // 578 psychic
  { "ZYTOMEGA", 0, 0, R_EVO, 0xD28F, 110, 65, 75, 30, 125, 85, 0, T_PSYCHIC, T_NONE },  // 579 psychic
  { "PICCOLENTE", 581, 35, R_COMUN, 0x4C98, 62, 44, 50, 55, 44, 50, 1, T_WATER, T_FLYING },  // 580 water/flying
  { "SWARONESS", 0, 0, R_EVO, 0x4C98, 75, 87, 63, 98, 87, 63, 1, T_WATER, T_FLYING },  // 581 water/flying
  { "GELATINI", 583, 35, R_COMUN, 0x4DB8, 36, 50, 50, 44, 65, 60, 5, T_ICE, T_NONE },  // 582 ice
  { "GELATROPPO", 584, 47, R_EVO, 0x4DB8, 51, 65, 65, 59, 80, 75, 5, T_ICE, T_NONE },  // 583 ice
  { "GELATWINO", 0, 0, R_EVO, 0x4DB8, 71, 95, 85, 79, 110, 95, 5, T_ICE, T_NONE },  // 584 ice
  { "SESOKITZ", 586, 34, R_COMUN, 0x8C4D, 60, 60, 50, 75, 40, 50, 0, T_NORMAL, T_GRASS },  // 585 normal/grass
  { "KRONJUWILD", 0, 0, R_EVO, 0x8C4D, 80, 100, 70, 95, 60, 70, 0, T_NORMAL, T_GRASS },  // 586 normal/grass
  { "EMOLGA", 0, 0, R_COMUN, 0xBCA1, 55, 75, 60, 103, 75, 60, 0, T_ELECTRIC, T_FLYING },  // 587 electric/flying
  { "LAUKAPS", 589, 40, R_COMUN, 0x7CC4, 50, 75, 45, 60, 40, 45, 2, T_BUG, T_NONE },  // 588 bug
  { "CAVALANZAS", 0, 0, R_EVO, 0x7CC4, 70, 135, 105, 20, 60, 105, 2, T_BUG, T_STEEL },  // 589 bug/steel
  { "TARNPIGNON", 591, 39, R_COMUN, 0x3C49, 69, 55, 45, 15, 55, 55, 2, T_GRASS, T_POISON },  // 590 grass/poison
  { "HUTSASSA", 0, 0, R_EVO, 0x3C49, 114, 85, 70, 30, 85, 80, 2, T_GRASS, T_POISON },  // 591 grass/poison
  { "QUABBEL", 593, 40, R_COMUN, 0x4C98, 55, 40, 50, 40, 65, 85, 1, T_WATER, T_GHOST },  // 592 water/ghost
  { "APOQUALLYP", 0, 0, R_EVO, 0x4C98, 100, 60, 70, 60, 85, 105, 1, T_WATER, T_GHOST },  // 593 water/ghost
  { "MAMOLIDA", 0, 0, R_COMUN, 0x4C98, 165, 75, 80, 65, 40, 45, 1, T_WATER, T_NONE },  // 594 water
  { "WATTZAPF", 596, 36, R_COMUN, 0x7CC4, 50, 47, 50, 65, 57, 50, 2, T_BUG, T_ELECTRIC },  // 595 bug/electric
  { "VOLTULA", 0, 0, R_EVO, 0x7CC4, 70, 77, 60, 108, 97, 60, 2, T_BUG, T_ELECTRIC },  // 596 bug/electric
  { "KASTADUR", 598, 40, R_COMUN, 0x3C49, 44, 50, 91, 10, 24, 86, 2, T_GRASS, T_STEEL },  // 597 grass/steel
  { "TENTANTEL", 0, 0, R_EVO, 0x3C49, 74, 94, 131, 20, 54, 116, 2, T_GRASS, T_STEEL },  // 598 grass/steel
  { "KLIKK", 600, 38, R_COMUN, 0x6BF1, 40, 55, 70, 30, 45, 60, 4, T_STEEL, T_NONE },  // 599 steel
  { "KLIKLAK", 601, 49, R_EVO, 0x6BF1, 60, 80, 95, 50, 70, 85, 4, T_STEEL, T_NONE },  // 600 steel
  { "KLIKDIKLAK", 0, 0, R_EVO, 0x6BF1, 60, 100, 115, 90, 70, 85, 4, T_STEEL, T_NONE },  // 601 steel
  { "ZAPPLARDIN", 603, 39, R_COMUN, 0xBCA1, 35, 55, 40, 60, 45, 40, 0, T_ELECTRIC, T_NONE },  // 602 electric
  { "ZAPPLALEK", 604, 30, R_EVO, 0xBCA1, 65, 85, 70, 40, 75, 70, 0, T_ELECTRIC, T_NONE },  // 603 electric
  { "ZAPPLARANG", 0, 0, R_EVO, 0xBCA1, 85, 115, 80, 50, 105, 80, 0, T_ELECTRIC, T_NONE },  // 604 electric
  { "PYGRAULON", 606, 42, R_COMUN, 0xD28F, 55, 55, 55, 30, 85, 55, 0, T_PSYCHIC, T_NONE },  // 605 psychic
  { "MEGALON", 0, 0, R_EVO, 0xD28F, 75, 75, 75, 40, 125, 95, 0, T_PSYCHIC, T_NONE },  // 606 psychic
  { "LICHTEL", 608, 41, R_COMUN, 0x6AD3, 50, 30, 55, 20, 65, 55, 0, T_GHOST, T_FIRE },  // 607 ghost/fire
  { "LATERNECTO", 609, 30, R_EVO, 0x6AD3, 60, 40, 60, 55, 95, 60, 0, T_GHOST, T_FIRE },  // 608 ghost/fire
  { "SKELABRA", 0, 0, R_EVO, 0x6AD3, 60, 55, 90, 80, 145, 90, 0, T_GHOST, T_FIRE },  // 609 ghost/fire
  { "MILZA", 611, 38, R_COMUN, 0x5A98, 46, 87, 60, 57, 30, 40, 1, T_DRAGON, T_NONE },  // 610 dragon
  { "SHARFAX", 612, 48, R_EVO, 0x5A98, 66, 117, 70, 67, 40, 50, 1, T_DRAGON, T_NONE },  // 611 dragon
  { "MAXAX", 0, 0, R_EVO, 0x5A98, 76, 147, 90, 97, 60, 70, 1, T_DRAGON, T_NONE },  // 612 dragon
  { "PETZNIEF", 614, 37, R_COMUN, 0x4DB8, 55, 70, 40, 40, 60, 40, 5, T_ICE, T_NONE },  // 613 ice
  { "SIBERIO", 0, 0, R_EVO, 0x4DB8, 95, 130, 80, 50, 70, 80, 5, T_ICE, T_NONE },  // 614 ice
  { "FRIGOMETRI", 0, 0, R_RARO, 0x4DB8, 80, 50, 50, 105, 95, 135, 5, T_ICE, T_NONE },  // 615 ice
  { "SCHNUTHELM", 617, 40, R_COMUN, 0x7CC4, 50, 40, 85, 25, 40, 65, 2, T_BUG, T_NONE },  // 616 bug
  { "HYDRAGIL", 0, 0, R_EVO, 0x7CC4, 80, 70, 40, 145, 100, 60, 2, T_BUG, T_NONE },  // 617 bug
  { "FLUNSCHLIK", 0, 0, R_COMUN, 0xB447, 109, 66, 84, 32, 81, 99, 4, T_GROUND, T_ELECTRIC },  // 618 ground/electric
  { "LIN-FU", 620, 50, R_COMUN, 0xA2A5, 45, 85, 50, 65, 55, 50, 0, T_FIGHTING, T_NONE },  // 619 fighting
  { "WIE-SHU", 0, 0, R_EVO, 0xA2A5, 65, 125, 60, 105, 95, 60, 0, T_FIGHTING, T_NONE },  // 620 fighting
  { "SHARDRAGO", 0, 0, R_RARO, 0x5A98, 77, 120, 90, 48, 60, 90, 1, T_DRAGON, T_NONE },  // 621 dragon
  { "GOLBIT", 623, 43, R_COMUN, 0xB447, 59, 74, 50, 35, 35, 50, 4, T_GROUND, T_GHOST },  // 622 ground/ghost
  { "GOLGANTES", 0, 0, R_EVO, 0xB447, 89, 124, 80, 55, 55, 80, 4, T_GROUND, T_GHOST },  // 623 ground/ghost
  { "GLADIANTRI", 625, 52, R_COMUN, 0x5A47, 45, 85, 70, 60, 40, 40, 2, T_DARK, T_STEEL },  // 624 dark/steel
  { "CAESURIO", 0, 0, R_EVO, 0x5A47, 65, 125, 100, 70, 60, 70, 2, T_DARK, T_STEEL },  // 625 dark/steel
  { "BISOFANK", 0, 0, R_RARO, 0x8C4D, 95, 110, 95, 55, 40, 95, 0, T_NORMAL, T_NONE },  // 626 normal
  { "GERONIMATZ", 628, 54, R_COMUN, 0x8C4D, 70, 83, 50, 60, 37, 50, 0, T_NORMAL, T_FLYING },  // 627 normal/flying
  { "WASHAKWIL", 0, 0, R_EVO, 0x8C4D, 100, 123, 75, 80, 57, 75, 0, T_NORMAL, T_FLYING },  // 628 normal/flying
  { "SKALLYK", 630, 54, R_COMUN, 0x5A47, 70, 55, 75, 60, 45, 65, 2, T_DARK, T_FLYING },  // 629 dark/flying
  { "GRYPHELDIS", 0, 0, R_EVO, 0x5A47, 110, 65, 105, 80, 55, 95, 2, T_DARK, T_FLYING },  // 630 dark/flying
  { "FURNIFRASS", 0, 0, R_COMUN, 0xEA87, 85, 97, 66, 65, 105, 66, 3, T_FIRE, T_NONE },  // 631 fire
  { "FERMICULA", 0, 0, R_COMUN, 0x7CC4, 58, 109, 112, 109, 48, 48, 2, T_BUG, T_STEEL },  // 632 bug/steel
  { "KAPUNO", 634, 50, R_RARO, 0x5A47, 52, 65, 50, 38, 45, 50, 2, T_DARK, T_DRAGON },  // 633 dark/dragon
  { "DUODINO", 635, 64, R_EVO, 0x5A47, 72, 85, 70, 58, 65, 70, 2, T_DARK, T_DRAGON },  // 634 dark/dragon
  { "TRIKEPHALO", 0, 0, R_EVO, 0x5A47, 92, 105, 90, 98, 125, 90, 2, T_DARK, T_DRAGON },  // 635 dark/dragon
  { "IGNIVOR", 637, 59, R_RARO, 0x7CC4, 55, 85, 55, 60, 50, 55, 2, T_BUG, T_FIRE },  // 636 bug/fire
  { "RAMOTH", 0, 0, R_EVO, 0x7CC4, 85, 60, 65, 100, 135, 105, 2, T_BUG, T_FIRE },  // 637 bug/fire
  { "KOBALIUM", 0, 0, R_LEGENDARIO, 0x6BF1, 91, 90, 129, 108, 90, 72, 4, T_STEEL, T_FIGHTING },  // 638 steel/fighting
  { "TERRAKIUM", 0, 0, R_LEGENDARIO, 0x9407, 91, 129, 90, 108, 72, 90, 4, T_ROCK, T_FIGHTING },  // 639 rock/fighting
  { "VIRIDIUM", 0, 0, R_LEGENDARIO, 0x3C49, 91, 90, 72, 108, 90, 129, 2, T_GRASS, T_FIGHTING },  // 640 grass/fighting
  { "BOREOS", 0, 0, R_LEGENDARIO, 0x7C7A, 79, 115, 70, 111, 125, 80, 0, T_FLYING, T_NONE },  // 641 flying
  { "VOLTOLOS", 0, 0, R_LEGENDARIO, 0xBCA1, 79, 115, 70, 111, 125, 80, 0, T_ELECTRIC, T_FLYING },  // 642 electric/flying
  { "RESHIRAM", 0, 0, R_LEGENDARIO, 0x5A98, 100, 120, 100, 90, 150, 120, 1, T_DRAGON, T_FIRE },  // 643 dragon/fire
  { "ZEKROM", 0, 0, R_LEGENDARIO, 0x5A98, 100, 150, 120, 90, 120, 100, 1, T_DRAGON, T_ELECTRIC },  // 644 dragon/electric
  { "DEMETEROS", 0, 0, R_LEGENDARIO, 0xB447, 89, 125, 90, 101, 115, 80, 4, T_GROUND, T_FLYING },  // 645 ground/flying
  { "KYUREM", 0, 0, R_LEGENDARIO, 0x5A98, 125, 130, 90, 95, 130, 90, 1, T_DRAGON, T_ICE },  // 646 dragon/ice
  { "KELDEO", 0, 0, R_LEGENDARIO, 0x4C98, 91, 72, 90, 108, 129, 90, 1, T_WATER, T_FIGHTING },  // 647 water/fighting
  { "MELOETTA", 0, 0, R_LEGENDARIO, 0x8C4D, 100, 77, 77, 90, 128, 128, 0, T_NORMAL, T_PSYCHIC },  // 648 normal/psychic
  { "GENESECT", 0, 0, R_LEGENDARIO, 0x7CC4, 71, 120, 95, 99, 120, 95, 2, T_BUG, T_STEEL },  // 649 bug/steel
  { "IGAMARO", 651, 16, R_RARO, 0x3C49, 56, 61, 65, 38, 48, 45, 2, T_GRASS, T_NONE },  // 650 grass
  { "IGASTARNISH", 652, 36, R_EVO, 0x3C49, 61, 78, 95, 57, 56, 58, 2, T_GRASS, T_NONE },  // 651 grass
  { "BRIGARON", 0, 0, R_EVO, 0x3C49, 88, 107, 122, 64, 74, 75, 2, T_GRASS, T_FIGHTING },  // 652 grass/fighting
  { "FYNX", 654, 16, R_RARO, 0xEA87, 40, 45, 40, 60, 62, 60, 3, T_FIRE, T_NONE },  // 653 fire
  { "RUTENA", 655, 36, R_EVO, 0xEA87, 59, 59, 58, 73, 90, 70, 3, T_FIRE, T_NONE },  // 654 fire
  { "FENNEXIS", 0, 0, R_EVO, 0xEA87, 75, 69, 72, 104, 114, 100, 3, T_FIRE, T_PSYCHIC },  // 655 fire/psychic
  { "FROXY", 657, 16, R_RARO, 0x4C98, 41, 56, 40, 71, 62, 44, 1, T_WATER, T_NONE },  // 656 water
  { "AMPHIZEL", 658, 36, R_EVO, 0x4C98, 54, 63, 52, 97, 83, 56, 1, T_WATER, T_NONE },  // 657 water
  { "QUAJUTSU", 0, 0, R_EVO, 0x4C98, 72, 95, 67, 122, 103, 71, 1, T_WATER, T_DARK },  // 658 water/dark
  { "SCOPPEL", 660, 20, R_COMUN, 0x8C4D, 38, 36, 38, 57, 32, 36, 0, T_NORMAL, T_NONE },  // 659 normal
  { "GREBBIT", 0, 0, R_EVO, 0x8C4D, 85, 56, 77, 78, 50, 77, 0, T_NORMAL, T_GROUND },  // 660 normal/ground
  { "DARTIRI", 662, 17, R_COMUN, 0x8C4D, 45, 50, 43, 62, 40, 38, 0, T_NORMAL, T_FLYING },  // 661 normal/flying
  { "DARTIGNIS", 663, 35, R_EVO, 0xEA87, 62, 73, 55, 84, 56, 52, 3, T_FIRE, T_FLYING },  // 662 fire/flying
  { "FIARO", 0, 0, R_EVO, 0xEA87, 78, 81, 71, 126, 74, 69, 3, T_FIRE, T_FLYING },  // 663 fire/flying
  { "PURMEL", 665, 9, R_COMUN, 0x7CC4, 38, 35, 40, 35, 27, 25, 2, T_BUG, T_NONE },  // 664 bug
  { "PUPONCHO", 666, 12, R_EVO, 0x7CC4, 45, 22, 60, 29, 27, 30, 2, T_BUG, T_NONE },  // 665 bug
  { "VIVILLON", 0, 0, R_EVO, 0x7CC4, 80, 52, 50, 89, 90, 50, 2, T_BUG, T_FLYING },  // 666 bug/flying
  { "LEUFEO", 668, 35, R_COMUN, 0xEA87, 62, 50, 58, 72, 73, 54, 3, T_FIRE, T_NORMAL },  // 667 fire/normal
  { "PYROLEO", 0, 0, R_EVO, 0xEA87, 86, 68, 72, 106, 109, 66, 3, T_FIRE, T_NORMAL },  // 668 fire/normal
  { "FLABEBE", 670, 19, R_COMUN, 0xC333, 44, 38, 39, 42, 61, 79, 0, T_FAIRY, T_NONE },  // 669 fairy
  { "FLOETTE", 671, 30, R_EVO, 0xC333, 54, 45, 47, 52, 75, 98, 0, T_FAIRY, T_NONE },  // 670 fairy
  { "FLORGES", 0, 0, R_EVO, 0xC333, 78, 65, 68, 75, 112, 154, 0, T_FAIRY, T_NONE },  // 671 fairy
  { "MAEHIKEL", 673, 32, R_COMUN, 0x3C49, 66, 65, 48, 52, 62, 57, 2, T_GRASS, T_NONE },  // 672 grass
  { "CHEVRUMM", 0, 0, R_EVO, 0x3C49, 123, 100, 62, 68, 97, 81, 2, T_GRASS, T_NONE },  // 673 grass
  { "PAM-PAM", 675, 32, R_COMUN, 0xA2A5, 67, 82, 62, 43, 46, 48, 0, T_FIGHTING, T_NONE },  // 674 fighting
  { "PANDAGRO", 0, 0, R_EVO, 0xA2A5, 95, 124, 78, 58, 69, 71, 0, T_FIGHTING, T_DARK },  // 675 fighting/dark
  { "COIFFWAFF", 0, 0, R_COMUN, 0x8C4D, 75, 80, 60, 102, 65, 90, 0, T_NORMAL, T_NONE },  // 676 normal
  { "PSIAU", 678, 25, R_COMUN, 0xD28F, 62, 48, 54, 68, 63, 60, 0, T_PSYCHIC, T_NONE },  // 677 psychic
  { "PSIAUGON", 0, 0, R_EVO, 0xD28F, 74, 48, 76, 104, 83, 81, 0, T_PSYCHIC, T_NONE },  // 678 psychic
  { "GRAMOKLES", 680, 35, R_COMUN, 0x6BF1, 45, 80, 100, 28, 35, 37, 4, T_STEEL, T_GHOST },  // 679 steel/ghost
  { "DUOKLES", 681, 30, R_EVO, 0x6BF1, 59, 110, 150, 35, 45, 49, 4, T_STEEL, T_GHOST },  // 680 steel/ghost
  { "DURENGARD", 0, 0, R_EVO, 0x6BF1, 60, 50, 140, 60, 50, 140, 4, T_STEEL, T_GHOST },  // 681 steel/ghost
  { "PARFI", 683, 40, R_COMUN, 0xC333, 78, 52, 60, 23, 63, 65, 0, T_FAIRY, T_NONE },  // 682 fairy
  { "PARFINESSE", 0, 0, R_EVO, 0xC333, 101, 72, 72, 29, 99, 89, 0, T_FAIRY, T_NONE },  // 683 fairy
  { "FLAUSCHLING", 685, 40, R_COMUN, 0xC333, 62, 48, 66, 49, 59, 57, 0, T_FAIRY, T_NONE },  // 684 fairy
  { "SABBAIONE", 0, 0, R_EVO, 0xC333, 82, 80, 86, 72, 85, 75, 0, T_FAIRY, T_NONE },  // 685 fairy
  { "ISCALAR", 687, 30, R_COMUN, 0x5A47, 53, 54, 53, 45, 37, 46, 2, T_DARK, T_PSYCHIC },  // 686 dark/psychic
  { "CALAMANERO", 0, 0, R_EVO, 0x5A47, 86, 92, 88, 73, 68, 75, 2, T_DARK, T_PSYCHIC },  // 687 dark/psychic
  { "BITHORA", 689, 39, R_COMUN, 0x9407, 42, 52, 67, 50, 39, 56, 4, T_ROCK, T_WATER },  // 688 rock/water
  { "THANATHORA", 0, 0, R_EVO, 0x9407, 72, 105, 115, 68, 54, 86, 4, T_ROCK, T_WATER },  // 689 rock/water
  { "ALGITT", 691, 48, R_COMUN, 0x8A73, 50, 60, 60, 30, 60, 60, 0, T_POISON, T_WATER },  // 690 poison/water
  { "TANDRAK", 0, 0, R_EVO, 0x8A73, 65, 75, 90, 44, 97, 123, 0, T_POISON, T_DRAGON },  // 691 poison/dragon
  { "SCAMPISTO", 693, 37, R_COMUN, 0x4C98, 50, 53, 62, 44, 58, 63, 1, T_WATER, T_NONE },  // 692 water
  { "WUMMER", 0, 0, R_EVO, 0x4C98, 71, 73, 88, 59, 120, 89, 1, T_WATER, T_NONE },  // 693 water
  { "EGUANA", 695, 30, R_COMUN, 0xBCA1, 44, 38, 33, 70, 61, 43, 0, T_ELECTRIC, T_NORMAL },  // 694 electric/normal
  { "ELEZARD", 0, 0, R_EVO, 0xBCA1, 62, 55, 52, 109, 109, 94, 0, T_ELECTRIC, T_NORMAL },  // 695 electric/normal
  { "BALGORAS", 697, 39, R_RARO, 0x9407, 58, 89, 77, 48, 45, 45, 4, T_ROCK, T_DRAGON },  // 696 rock/dragon
  { "MONARGORAS", 0, 0, R_EVO, 0x9407, 82, 121, 119, 71, 69, 59, 4, T_ROCK, T_DRAGON },  // 697 rock/dragon
  { "AMARINO", 699, 39, R_RARO, 0x9407, 77, 59, 50, 46, 67, 63, 4, T_ROCK, T_ICE },  // 698 rock/ice
  { "AMAGARGA", 0, 0, R_EVO, 0x9407, 123, 77, 72, 58, 99, 92, 4, T_ROCK, T_ICE },  // 699 rock/ice
  { "FEELINARA", 0, 0, R_EVO, 0xC333, 95, 65, 65, 60, 110, 130, 0, T_FAIRY, T_NONE },  // 700 fairy
  { "RESLADERO", 0, 0, R_COMUN, 0xA2A5, 78, 92, 75, 118, 74, 63, 0, T_FIGHTING, T_FLYING },  // 701 fighting/flying
  { "DEDENNE", 0, 0, R_COMUN, 0xBCA1, 67, 58, 57, 101, 81, 67, 0, T_ELECTRIC, T_FAIRY },  // 702 electric/fairy
  { "ROCARA", 0, 0, R_COMUN, 0x9407, 50, 50, 150, 50, 50, 150, 4, T_ROCK, T_FAIRY },  // 703 rock/fairy
  { "VISCORA", 705, 40, R_RARO, 0x5A98, 45, 50, 35, 40, 55, 75, 1, T_DRAGON, T_NONE },  // 704 dragon
  { "VISCARGOT", 706, 50, R_EVO, 0x5A98, 68, 75, 53, 60, 83, 113, 1, T_DRAGON, T_NONE },  // 705 dragon
  { "VISCOGON", 0, 0, R_EVO, 0x5A98, 90, 100, 70, 80, 110, 150, 1, T_DRAGON, T_NONE },  // 706 dragon
  { "CLAVION", 0, 0, R_COMUN, 0x6BF1, 57, 80, 91, 75, 80, 87, 4, T_STEEL, T_FAIRY },  // 707 steel/fairy
  { "PARAGONI", 709, 40, R_COMUN, 0x6AD3, 43, 70, 48, 38, 50, 60, 0, T_GHOST, T_GRASS },  // 708 ghost/grass
  { "TROMBORK", 0, 0, R_EVO, 0x6AD3, 85, 110, 76, 56, 65, 82, 0, T_GHOST, T_GRASS },  // 709 ghost/grass
  { "IRRBIS", 711, 40, R_COMUN, 0x6AD3, 49, 66, 70, 51, 44, 55, 0, T_GHOST, T_GRASS },  // 710 ghost/grass
  { "PUMPDJINN", 0, 0, R_EVO, 0x6AD3, 65, 90, 122, 84, 58, 75, 0, T_GHOST, T_GRASS },  // 711 ghost/grass
  { "ARKTIP", 713, 37, R_COMUN, 0x4DB8, 55, 69, 85, 28, 32, 35, 5, T_ICE, T_NONE },  // 712 ice
  { "ARKTILAS", 0, 0, R_EVO, 0x4DB8, 95, 117, 184, 28, 44, 46, 5, T_ICE, T_NONE },  // 713 ice
  { "EF-EM", 715, 48, R_COMUN, 0x7C7A, 40, 30, 35, 55, 45, 40, 0, T_FLYING, T_DRAGON },  // 714 flying/dragon
  { "UHAFNIR", 0, 0, R_EVO, 0x7C7A, 85, 70, 80, 123, 97, 80, 0, T_FLYING, T_DRAGON },  // 715 flying/dragon
  { "XERNEAS", 0, 0, R_LEGENDARIO, 0xC333, 126, 131, 95, 99, 131, 98, 0, T_FAIRY, T_NONE },  // 716 fairy
  { "YVELTAL", 0, 0, R_LEGENDARIO, 0x5A47, 126, 131, 95, 99, 131, 98, 2, T_DARK, T_FLYING },  // 717 dark/flying
  { "ZYGARDE", 0, 0, R_LEGENDARIO, 0x5A98, 108, 100, 121, 95, 81, 95, 1, T_DRAGON, T_GROUND },  // 718 dragon/ground
  { "DIANCIE", 0, 0, R_LEGENDARIO, 0x9407, 50, 100, 150, 50, 100, 150, 4, T_ROCK, T_FAIRY },  // 719 rock/fairy
  { "HOOPA", 0, 0, R_LEGENDARIO, 0xD28F, 80, 110, 60, 70, 150, 130, 0, T_PSYCHIC, T_GHOST },  // 720 psychic/ghost
  { "VOLCANION", 0, 0, R_LEGENDARIO, 0xEA87, 80, 110, 120, 70, 130, 90, 3, T_FIRE, T_WATER },  // 721 fire/water
  { "BAUZ", 723, 17, R_RARO, 0x3C49, 68, 55, 55, 42, 50, 50, 2, T_GRASS, T_FLYING },  // 722 grass/flying
  { "ARBORETOSS", 724, 34, R_EVO, 0x3C49, 78, 75, 75, 52, 70, 70, 2, T_GRASS, T_FLYING },  // 723 grass/flying
  { "SILVARRO", 0, 0, R_EVO, 0x3C49, 78, 107, 75, 70, 100, 100, 2, T_GRASS, T_GHOST },  // 724 grass/ghost
  { "FLAMIAU", 726, 17, R_RARO, 0xEA87, 45, 65, 40, 70, 60, 40, 3, T_FIRE, T_NONE },  // 725 fire
  { "MIEZUNDER", 727, 34, R_EVO, 0xEA87, 65, 85, 50, 90, 80, 50, 3, T_FIRE, T_NONE },  // 726 fire
  { "FUEGRO", 0, 0, R_EVO, 0xEA87, 95, 115, 90, 60, 80, 90, 3, T_FIRE, T_DARK },  // 727 fire/dark
  { "ROBBALL", 729, 17, R_RARO, 0x4C98, 50, 54, 54, 40, 66, 56, 1, T_WATER, T_NONE },  // 728 water
  { "MARIKECK", 730, 34, R_EVO, 0x4C98, 60, 69, 69, 50, 91, 81, 1, T_WATER, T_NONE },  // 729 water
  { "PRIMARENE", 0, 0, R_EVO, 0x4C98, 80, 74, 74, 60, 126, 116, 1, T_WATER, T_FAIRY },  // 730 water/fairy
  { "PEPPECK", 732, 14, R_COMUN, 0x8C4D, 35, 75, 30, 65, 30, 30, 0, T_NORMAL, T_FLYING },  // 731 normal/flying
  { "TROMPECK", 733, 28, R_EVO, 0x8C4D, 55, 85, 50, 75, 40, 50, 0, T_NORMAL, T_FLYING },  // 732 normal/flying
  { "TUKANON", 0, 0, R_EVO, 0x8C4D, 80, 120, 75, 60, 75, 75, 0, T_NORMAL, T_FLYING },  // 733 normal/flying
  { "MANGUNIOR", 735, 20, R_COMUN, 0x8C4D, 48, 70, 30, 45, 30, 30, 0, T_NORMAL, T_NONE },  // 734 normal
  { "MANGUSPEKTOR", 0, 0, R_EVO, 0x8C4D, 88, 110, 60, 45, 55, 60, 0, T_NORMAL, T_NONE },  // 735 normal
  { "MABULA", 737, 20, R_COMUN, 0x7CC4, 47, 62, 45, 46, 55, 45, 2, T_BUG, T_NONE },  // 736 bug
  { "AKKUP", 738, 30, R_EVO, 0x7CC4, 57, 82, 95, 36, 55, 75, 2, T_BUG, T_ELECTRIC },  // 737 bug/electric
  { "DONARION", 0, 0, R_EVO, 0x7CC4, 77, 70, 90, 43, 145, 75, 2, T_BUG, T_ELECTRIC },  // 738 bug/electric
  { "KRABBOX", 740, 30, R_COMUN, 0xA2A5, 47, 82, 57, 63, 42, 47, 0, T_FIGHTING, T_NONE },  // 739 fighting
  { "KRAWELL", 0, 0, R_EVO, 0xA2A5, 97, 132, 77, 43, 62, 67, 0, T_FIGHTING, T_ICE },  // 740 fighting/ice
  { "CHOREOGEL", 0, 0, R_RARO, 0xEA87, 75, 70, 70, 93, 98, 70, 3, T_FIRE, T_FLYING },  // 741 fire/flying
  { "WOMMEL", 743, 25, R_COMUN, 0x7CC4, 40, 45, 40, 84, 55, 40, 2, T_BUG, T_FAIRY },  // 742 bug/fairy
  { "BANDELBY", 0, 0, R_EVO, 0x7CC4, 60, 55, 60, 124, 95, 70, 2, T_BUG, T_FAIRY },  // 743 bug/fairy
  { "WUFFELS", 745, 25, R_COMUN, 0x9407, 45, 65, 40, 60, 30, 40, 4, T_ROCK, T_NONE },  // 744 rock
  { "WOLWEROCK", 0, 0, R_EVO, 0x9407, 75, 115, 65, 112, 55, 65, 4, T_ROCK, T_NONE },  // 745 rock
  { "LUSARDIN", 0, 0, R_COMUN, 0x4C98, 45, 20, 20, 40, 25, 25, 1, T_WATER, T_NONE },  // 746 water
  { "GARSTELLA", 748, 38, R_COMUN, 0x8A73, 50, 53, 62, 45, 43, 52, 0, T_POISON, T_WATER },  // 747 poison/water
  { "AGGROSTELLA", 0, 0, R_EVO, 0x8A73, 50, 63, 152, 35, 53, 142, 0, T_POISON, T_WATER },  // 748 poison/water
  { "PAMPULI", 750, 30, R_COMUN, 0xB447, 70, 100, 70, 45, 45, 55, 4, T_GROUND, T_NONE },  // 749 ground
  { "PAMPROSS", 0, 0, R_EVO, 0xB447, 100, 125, 100, 35, 55, 85, 4, T_GROUND, T_NONE },  // 750 ground
  { "ARAQUA", 752, 22, R_COMUN, 0x4C98, 38, 40, 52, 27, 40, 72, 1, T_WATER, T_BUG },  // 751 water/bug
  { "ARANESTRO", 0, 0, R_EVO, 0x4C98, 68, 70, 92, 42, 50, 132, 1, T_WATER, T_BUG },  // 752 water/bug
  { "IMANTIS", 754, 34, R_COMUN, 0x3C49, 40, 55, 35, 35, 50, 35, 2, T_GRASS, T_NONE },  // 753 grass
  { "MANTIDEA", 0, 0, R_EVO, 0x3C49, 70, 105, 90, 45, 80, 90, 2, T_GRASS, T_NONE },  // 754 grass
  { "BUBUNGUS", 756, 24, R_COMUN, 0x3C49, 40, 35, 55, 15, 65, 75, 2, T_GRASS, T_FAIRY },  // 755 grass/fairy
  { "LAMELLUX", 0, 0, R_EVO, 0x3C49, 60, 45, 80, 30, 90, 100, 2, T_GRASS, T_FAIRY },  // 756 grass/fairy
  { "MOLUNK", 758, 33, R_COMUN, 0x8A73, 48, 44, 40, 77, 71, 40, 0, T_POISON, T_FIRE },  // 757 poison/fire
  { "AMFIRA", 0, 0, R_EVO, 0x8A73, 68, 64, 60, 117, 111, 60, 0, T_POISON, T_FIRE },  // 758 poison/fire
  { "VELURSI", 760, 27, R_COMUN, 0x8C4D, 70, 75, 50, 50, 45, 50, 0, T_NORMAL, T_FIGHTING },  // 759 normal/fighting
  { "KOSTURSO", 0, 0, R_EVO, 0x8C4D, 120, 125, 80, 60, 55, 60, 0, T_NORMAL, T_FIGHTING },  // 760 normal/fighting
  { "FRUBBERL", 762, 18, R_COMUN, 0x3C49, 42, 30, 38, 32, 30, 38, 2, T_GRASS, T_NONE },  // 761 grass
  { "FRUBAILA", 763, 30, R_EVO, 0x3C49, 52, 40, 48, 62, 40, 48, 2, T_GRASS, T_NONE },  // 762 grass
  { "FRUYAL", 0, 0, R_EVO, 0x3C49, 72, 120, 98, 72, 50, 98, 2, T_GRASS, T_NONE },  // 763 grass
  { "CURELEI", 0, 0, R_COMUN, 0xC333, 51, 52, 90, 100, 82, 110, 0, T_FAIRY, T_NONE },  // 764 fairy
  { "KOMMANDUTAN", 0, 0, R_RARO, 0x8C4D, 90, 60, 80, 60, 90, 110, 0, T_NORMAL, T_PSYCHIC },  // 765 normal/psychic
  { "QUARTERMAK", 0, 0, R_RARO, 0xA2A5, 100, 120, 90, 80, 40, 60, 0, T_FIGHTING, T_NONE },  // 766 fighting
  { "REISSLAUS", 768, 30, R_COMUN, 0x7CC4, 25, 35, 40, 80, 20, 30, 2, T_BUG, T_WATER },  // 767 bug/water
  { "TECTASS", 0, 0, R_EVO, 0x7CC4, 75, 125, 140, 40, 60, 90, 2, T_BUG, T_WATER },  // 768 bug/water
  { "SANKABUH", 770, 42, R_COMUN, 0x6AD3, 55, 55, 80, 15, 70, 45, 0, T_GHOST, T_GROUND },  // 769 ghost/ground
  { "COLOSSAND", 0, 0, R_EVO, 0x6AD3, 85, 75, 110, 35, 100, 75, 0, T_GHOST, T_GROUND },  // 770 ghost/ground
  { "GUFA", 0, 0, R_COMUN, 0x4C98, 55, 60, 130, 5, 30, 130, 1, T_WATER, T_NONE },  // 771 water
  { "TYP:NULL", 773, 25, R_LEGENDARIO, 0x8C4D, 95, 95, 95, 59, 95, 95, 0, T_NORMAL, T_NONE },  // 772 normal
  { "AMIGENTO", 0, 0, R_EVO, 0x8C4D, 95, 95, 95, 95, 95, 95, 0, T_NORMAL, T_NONE },  // 773 normal
  { "METENO", 0, 0, R_RARO, 0x9407, 60, 60, 100, 60, 60, 100, 4, T_ROCK, T_FLYING },  // 774 rock/flying
  { "KOALELU", 0, 0, R_RARO, 0x8C4D, 65, 115, 65, 65, 75, 95, 0, T_NORMAL, T_NONE },  // 775 normal
  { "TORTUNATOR", 0, 0, R_COMUN, 0xEA87, 60, 78, 135, 36, 91, 85, 3, T_FIRE, T_DRAGON },  // 776 fire/dragon
  { "TOGEDEMARU", 0, 0, R_COMUN, 0xBCA1, 65, 98, 63, 96, 40, 73, 0, T_ELECTRIC, T_STEEL },  // 777 electric/steel
  { "MIMIGMA", 0, 0, R_RARO, 0x6AD3, 55, 90, 80, 96, 50, 105, 0, T_GHOST, T_FAIRY },  // 778 ghost/fairy
  { "KNIRFISH", 0, 0, R_COMUN, 0x4C98, 68, 105, 70, 92, 70, 70, 1, T_WATER, T_PSYCHIC },  // 779 water/psychic
  { "SEN-LONG", 0, 0, R_COMUN, 0x8C4D, 78, 60, 85, 36, 135, 91, 0, T_NORMAL, T_DRAGON },  // 780 normal/dragon
  { "MORUDA", 0, 0, R_RARO, 0x6AD3, 70, 131, 100, 40, 86, 90, 0, T_GHOST, T_GRASS },  // 781 ghost/grass
  { "MINIRAS", 783, 35, R_RARO, 0x5A98, 45, 55, 65, 45, 45, 45, 1, T_DRAGON, T_NONE },  // 782 dragon
  { "MEDIRAS", 784, 45, R_EVO, 0x5A98, 55, 75, 90, 65, 65, 70, 1, T_DRAGON, T_FIGHTING },  // 783 dragon/fighting
  { "GRANDIRAS", 0, 0, R_EVO, 0x5A98, 75, 110, 125, 85, 100, 105, 1, T_DRAGON, T_FIGHTING },  // 784 dragon/fighting
  { "KAPU-RIKI", 0, 0, R_LEGENDARIO, 0xBCA1, 70, 115, 85, 130, 95, 75, 0, T_ELECTRIC, T_FAIRY },  // 785 electric/fairy
  { "KAPU-FALA", 0, 0, R_LEGENDARIO, 0xD28F, 70, 85, 75, 95, 130, 115, 0, T_PSYCHIC, T_FAIRY },  // 786 psychic/fairy
  { "KAPU-TORO", 0, 0, R_LEGENDARIO, 0x3C49, 70, 130, 115, 75, 85, 95, 2, T_GRASS, T_FAIRY },  // 787 grass/fairy
  { "KAPU-KIME", 0, 0, R_LEGENDARIO, 0x4C98, 70, 75, 115, 85, 95, 130, 1, T_WATER, T_FAIRY },  // 788 water/fairy
  { "COSMOG", 790, 43, R_LEGENDARIO, 0xD28F, 43, 29, 31, 37, 29, 31, 0, T_PSYCHIC, T_NONE },  // 789 psychic
  { "COSMOVUM", 791, 53, R_EVO, 0xD28F, 43, 29, 131, 37, 29, 131, 0, T_PSYCHIC, T_NONE },  // 790 psychic
  { "SOLGALEO", 0, 0, R_EVO, 0xD28F, 137, 137, 107, 97, 113, 89, 0, T_PSYCHIC, T_STEEL },  // 791 psychic/steel
  { "LUNALA", 0, 0, R_LEGENDARIO, 0xD28F, 137, 113, 89, 97, 137, 107, 0, T_PSYCHIC, T_GHOST },  // 792 psychic/ghost
  { "ANEGO", 0, 0, R_RARO, 0x9407, 109, 53, 47, 103, 127, 131, 4, T_ROCK, T_POISON },  // 793 rock/poison
  { "MASSKITO", 0, 0, R_RARO, 0x7CC4, 107, 139, 139, 79, 53, 53, 2, T_BUG, T_FIGHTING },  // 794 bug/fighting
  { "SCHABELLE", 0, 0, R_RARO, 0x7CC4, 71, 137, 37, 151, 137, 37, 2, T_BUG, T_FIGHTING },  // 795 bug/fighting
  { "VOLTRIANT", 0, 0, R_RARO, 0xBCA1, 83, 89, 71, 83, 173, 71, 0, T_ELECTRIC, T_NONE },  // 796 electric
  { "KAGURON", 0, 0, R_RARO, 0x6BF1, 97, 101, 103, 61, 107, 101, 4, T_STEEL, T_FLYING },  // 797 steel/flying
  { "KATAGAMI", 0, 0, R_RARO, 0x3C49, 59, 181, 131, 109, 59, 31, 2, T_GRASS, T_STEEL },  // 798 grass/steel
  { "SCHLINGKING", 0, 0, R_RARO, 0x5A47, 223, 101, 53, 43, 97, 53, 2, T_DARK, T_DRAGON },  // 799 dark/dragon
  { "NECROZMA", 0, 0, R_LEGENDARIO, 0xD28F, 97, 107, 101, 79, 127, 89, 0, T_PSYCHIC, T_NONE },  // 800 psychic
  { "MAGEARNA", 0, 0, R_LEGENDARIO, 0x6BF1, 80, 95, 115, 65, 130, 115, 4, T_STEEL, T_FAIRY },  // 801 steel/fairy
  { "MARSHADOW", 0, 0, R_LEGENDARIO, 0xA2A5, 90, 125, 80, 125, 90, 90, 0, T_FIGHTING, T_GHOST },  // 802 fighting/ghost
  { "VENICRO", 804, 30, R_RARO, 0x8A73, 67, 73, 67, 73, 73, 67, 0, T_POISON, T_NONE },  // 803 poison
  { "AGOYON", 0, 0, R_EVO, 0x8A73, 73, 73, 73, 121, 127, 73, 0, T_POISON, T_DRAGON },  // 804 poison/dragon
  { "MURAMURA", 0, 0, R_RARO, 0x9407, 61, 131, 211, 13, 53, 101, 4, T_ROCK, T_STEEL },  // 805 rock/steel
  { "KOPPLOSIO", 0, 0, R_RARO, 0xEA87, 53, 127, 53, 107, 151, 79, 3, T_FIRE, T_GHOST },  // 806 fire/ghost
  { "ZERAORA", 0, 0, R_LEGENDARIO, 0xBCA1, 88, 112, 75, 143, 102, 80, 0, T_ELECTRIC, T_NONE },  // 807 electric
  { "MELTAN", 0, 0, R_LEGENDARIO, 0x6BF1, 46, 65, 65, 34, 55, 35, 4, T_STEEL, T_NONE },  // 808 steel
  { "MELMETAL", 0, 0, R_LEGENDARIO, 0x6BF1, 135, 143, 143, 34, 80, 65, 4, T_STEEL, T_NONE },  // 809 steel
};

// el primer huevo de la partida: iniciales clasicos
static const int16_t CLASSIC_DEX[] = { 1, 4, 7, 25, 133 };
#define NUM_CLASSIC_DEX 5

// Which generation an egg may come from. A region is decided by the BASE
// species, and evolutions follow wherever they lead.
struct RegionInfo {
  const char *name;
  uint16_t lo, hi;
  const int16_t *starters;
  uint8_t starterCount;
};
static const int16_t REGION_START_KANTO[] = { 1, 4, 7, 25, 133 };
static const int16_t REGION_START_JOHTO[] = { 152, 155, 158 };
static const int16_t REGION_START_HOENN[] = { 252, 255, 258 };
static const int16_t REGION_START_SINNOH[] = { 387, 390, 393 };
static const int16_t REGION_START_UNOVA[] = { 495, 498, 501 };
static const int16_t REGION_START_KALOS[] = { 650, 653, 656 };
static const int16_t REGION_START_ALOLA[] = { 722, 725, 728 };
static const int16_t REGION_START_ALL[] = { 1, 4, 7, 25, 133, 152, 155, 158, 252, 255, 258, 387, 390, 393, 495, 498, 501, 650, 653, 656, 722, 725, 728 };
#define REGION_COUNT 8
#define REGION_ALL 7
static const RegionInfo REGIONS[REGION_COUNT] = {
  { "KANTO", 1, 151, REGION_START_KANTO, 5 },
  { "JOHTO", 152, 251, REGION_START_JOHTO, 3 },
  { "HOENN", 252, 386, REGION_START_HOENN, 3 },
  { "SINNOH", 387, 493, REGION_START_SINNOH, 3 },
  { "UNOVA", 494, 649, REGION_START_UNOVA, 3 },
  { "KALOS", 650, 721, REGION_START_KALOS, 3 },
  { "ALOLA", 722, 809, REGION_START_ALOLA, 3 },
  { "ALL", 1, 809, REGION_START_ALL, 23 },
};
