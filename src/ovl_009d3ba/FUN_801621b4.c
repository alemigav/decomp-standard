/* FUN_801621b4
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x801621b4  body 0x801621b4..0x80162303  size 336 B
 * body sha256 0e5adf090cfc9790cc2e39689238801ec890f675312927284e26d2268f49735a
 * provider record sha256 702d32359a562f82538d92d05eebe7fa288c6f33a3e2bdc08efa169d08afdd1d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801621b4(int param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x28c);
  sVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x2f8);
  if (((uVar3 < 0x9c4) && (sVar1 == 0)) && (1 < *(byte *)(param_1 + 6))) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    FUN_80162d8c(param_1,*(byte *)(param_1 + 0x1ab) & 1);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2b8);
    *(undefined1 *)(param_1 + 0x26f) = 0;
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 700);
    if (*(short *)(param_1 + 0x2c0) != 1) {
      *(undefined2 *)(param_1 + 0x2c0) = 1;
      return;
    }
  }
  else {
    if (2999 < uVar3) {
      return;
    }
    if (sVar2 != 0) {
      return;
    }
    if (*(char *)(param_1 + 6) != '\x02') {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 3;
    FUN_80162d8c(param_1,*(byte *)(param_1 + 0x1ab) & 1);
    *(undefined1 *)(param_1 + 0x26f) = 0;
    if (*(short *)(param_1 + 0x2c0) != 1) {
      *(undefined2 *)(param_1 + 0x2c0) = 1;
      return;
    }
  }
  if (DAT_80163130 == '\0') {
    func_0x80077d18(4,param_1);
    DAT_80163130 = '<';
  }
  return;
}
