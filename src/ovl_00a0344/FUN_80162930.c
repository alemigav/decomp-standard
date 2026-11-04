/* FUN_80162930
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162930  body 0x80162930..0x80162a13  size 228 B
 * body sha256 542816061a7d69becf0d7ae18907cb09e8cbbdb9093dbd21ecfb72a219ad0f62
 * provider record sha256 43bc7a247e52e45d129ffc9c6b680fb9b2d8e32280805f47111702c53a7aa05e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162930(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar1 = func_0x80033604();
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = ((uVar1 & 1) + 1) * 0x1000000 + (uVar2 & 0xf) * 0x10000 + 0x700;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar3 != 0) {
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = ((uVar1 & 1) + 1) * 0x1000000 + 0x700;
  }
  if (((*(short *)(param_1 + 0x1aa) != 0x2021) && (*(char *)(param_1 + 0x2be) == '\0')) &&
     (*(uint *)(param_1 + 0x28c) < 2000)) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
