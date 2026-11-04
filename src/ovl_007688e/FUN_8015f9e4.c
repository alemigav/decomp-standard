/* FUN_8015f9e4
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015f9e4  body 0x8015f9e4..0x8015fb27  size 324 B
 * body sha256 60059646c1157c46f7ad073afb49de1adc21848ac797d5ca24de73fa461300be
 * provider record sha256 d7e60b62247397ac84b5737d3e5e53a749e79f2109bcbcc1fdea24b172bb4be9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015f9e4(undefined1 param_1,undefined1 param_2,int param_3)

{
  undefined *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  puVar1 = &UNK_801612fc;
  puVar2 = &DAT_80161318;
  iVar3 = 0x6e0;
  do {
    *(undefined4 **)(puVar1 + 0x28) = &DAT_80161480;
    *(undefined2 *)(puVar1 + 0x26) = 0;
    puVar1[0x1e] = param_1;
    puVar1[0x1d] = param_1;
    puVar1[0x1c] = param_1;
    func_0x80047b04(puVar2,param_3 == 0);
    uVar4 = uVar4 + 1;
    _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,puVar2,0,0);
    puVar1 = (undefined *)((int)&DAT_80160c44 + iVar3);
    puVar2 = puVar2 + 0x28;
    iVar3 = iVar3 + 0x28;
  } while (uVar4 < 4);
  DAT_801613c4 = &DAT_80161480;
  DAT_801613c2 = 0x200;
  DAT_801613b8 = param_2;
  DAT_801613b9 = param_2;
  DAT_801613ba = param_2;
  _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_801613b8,0,0);
  return;
}
