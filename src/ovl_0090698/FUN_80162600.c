/* FUN_80162600
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162600  body 0x80162600..0x801626fb  size 252 B
 * body sha256 2cd5b73be7195ff190d804fcc913717b1524ce3e0fe970981ab38bb1e544d600
 * provider record sha256 b6bb18bb65fa7bf6cf264ae6db38bd78044d677210a08893167d7d615a5d343d
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162600(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar2;
  uint uVar1;
  short sVar3;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000300;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar2 & 0xff) + 10 & 0x3f;
    *(undefined2 *)(param_1 + 0x1f6) = 0x18;
    uVar1 = func_0x80033604();
    if ((uVar1 & 1) != 0) {
      *(undefined2 *)(param_1 + 0x1f6) = 0xffe8;
    }
    if (*(char *)(param_1 + 0x2be) != '\0') {
      *(short *)(param_1 + 0x1f6) = -*(short *)(param_1 + 0x1f6);
    }
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  sVar3 = *(short *)(param_1 + 500) + -1;
  *(short *)(param_1 + 500) = sVar3;
  if (sVar3 == -1) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
  }
  return;
}
