/* FUN_80165618
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165618  body 0x80165618..0x801657cf  size 440 B
 * body sha256 a6d0f53b64686f70dffba9f6d05019e73647ce5f63bface14359f40b1bb5b9db
 * provider record sha256 b44175249c2d39d1022bf9b637df77ec7bcc4210aa8489b9dd7a07875c28c265
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165618(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3);
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,8,uVar1 & 3 | 4);
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,9,uVar1 & 3);
    uVar1 = func_0x80033604();
    FUN_801663a4(param_1,9,uVar1 & 3 | 4);
    uVar1 = 0;
    iVar2 = 0;
    do {
      uVar1 = uVar1 + 1;
      puVar3 = (uint *)(*(int *)(param_1 + 0x234) + iVar2);
      puVar3[0x18] = 0x301040;
      *(undefined2 *)(puVar3 + 0x49) = 0x1000;
      *(undefined2 *)((int)puVar3 + 0x126) = 0x1000;
      *(undefined2 *)(puVar3 + 0x4a) = 0x1000;
      *puVar3 = *puVar3 | 0x400;
      iVar2 = iVar2 + 0x178;
    } while (uVar1 < 0xd);
    iVar2 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar2 + 0x178) = *(uint *)(iVar2 + 0x178) | 0x10;
    *(undefined2 *)(iVar2 + 0x2a8) = 0;
    *(undefined2 *)(iVar2 + 0x2aa) = 0;
    *(undefined2 *)(iVar2 + 0x2ae) = 0x1e;
    *(undefined1 *)(iVar2 + 0x2ac) = 0x1e;
    *(undefined1 *)(iVar2 + 0x2ad) = 0x1e;
    FUN_801651c0(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_80166830)[*(byte *)(param_1 + 6)])(param_1,param_2,param_3);
  }
  if (*(char *)(param_1 + 0x2bd) != '\0') {
    uVar1 = 3;
    iVar2 = 0x468;
    do {
      iVar4 = *(int *)(param_1 + 0x234) + iVar2;
      uVar1 = uVar1 + 1;
      if (0xc00 < *(short *)(iVar4 + 0x124)) {
        *(short *)(iVar4 + 0x124) = *(short *)(iVar4 + 0x124) + -0x40;
        *(short *)(iVar4 + 0x126) = *(short *)(iVar4 + 0x126) + -0x40;
        *(short *)(iVar4 + 0x128) = *(short *)(iVar4 + 0x128) + -0x40;
      }
      iVar2 = iVar2 + 0x178;
    } while (uVar1 < 7);
  }
  return;
}
