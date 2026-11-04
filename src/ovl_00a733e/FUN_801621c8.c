/* FUN_801621c8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801621c8  body 0x801621c8..0x80162313  size 332 B
 * body sha256 2b136d4a91f75a15e12074a65791858acaa6ac360e0b31813b4b08bef1308b1b
 * provider record sha256 8bb9a7c5fd0d09af5b8d3c2ef333ce2c09ff609131af26bf60d6694292679086
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801621c8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    uVar4 = 0;
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined2 *)((int)param_1 + 0x272) = 0;
    param_1[0x7a] = 0xa000f00;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
    func_0x800334c8();
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined1 *)((int)param_1 + 0x2c9) = 1;
    *(undefined2 *)((int)param_1 + 0x212) = 0xd98;
    *param_1 = *param_1 | 0x800;
    do {
      puVar1 = &DAT_80167dbc + uVar4;
      uVar4 = uVar4 + 1;
      FUN_80167bd8(param_1,*puVar1,0,0xfff);
    } while (uVar4 < 8);
    uVar4 = 0x14;
    iVar3 = 0x1d60;
    do {
      uVar4 = uVar4 + 1;
      puVar2 = (uint *)(param_1[0x8d] + iVar3);
      *(undefined2 *)(puVar2 + 0x49) = 0x1000;
      *(undefined2 *)((int)puVar2 + 0x126) = 0;
      *(undefined2 *)(puVar2 + 0x4a) = 0x1000;
      *puVar2 = *puVar2 | 0x400;
      iVar3 = iVar3 + 0x178;
    } while (uVar4 < 0x17);
    FUN_80167bd8(param_1,0xb,0,0xfff);
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  }
  if (*(short *)(param_1 + 0x9c) == 1) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
  }
  return;
}
