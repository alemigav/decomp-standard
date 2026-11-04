/* FUN_801627d4
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x801627d4  body 0x801627d4..0x80162a6b  size 664 B
 * body sha256 c82be9cbe1d6e8b499a2836c8d5d8342c9d4e3c38958e00aede7de6ca954999f
 * provider record sha256 28f7ad77dfd15993d0e63f611cbe9471337f94125fc29e7fc61b05b9ec558aaf
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  short *psVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x207) = 1;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54(param_1,param_2,param_3,0x80);
  iVar2 = 0x10;
  psVar1 = (short *)(*(int *)(param_1 + 0x234) + 0x128);
  do {
    iVar2 = iVar2 + -1;
    psVar1[-2] = psVar1[-2] + *(char *)(param_1 + 0x207) * 0x23;
    psVar1[-1] = psVar1[-1] + *(char *)(param_1 + 0x207) * 0x23;
    *psVar1 = *psVar1 + *(char *)(param_1 + 0x207) * 0x23;
    psVar1 = psVar1 + 0xbc;
  } while (iVar2 != 0);
  *(short *)(param_1 + 0x27a) = *(short *)(param_1 + 0x27a) + *(char *)(param_1 + 0x207) * 0x10;
  iVar2 = *(int *)(*(int *)(param_1 + 0x234) + 0x298);
  *(short *)(iVar2 + 0xc) = *(short *)(iVar2 + 0xc) + *(char *)(param_1 + 0x207) * -200;
  func_0x80066288(param_1);
  iVar2 = *(int *)(*(int *)(param_1 + 0x234) + 0x410);
  *(short *)(iVar2 + 0xc) = *(short *)(iVar2 + 0xc) + *(char *)(param_1 + 0x207) * -200;
  func_0x80066288(param_1);
  iVar2 = *(int *)(*(int *)(param_1 + 0x234) + 0x878);
  *(short *)(iVar2 + 0xc) = *(short *)(iVar2 + 0xc) + *(char *)(param_1 + 0x207) * -200;
  func_0x80066288(param_1);
  iVar2 = *(int *)(param_1 + 0x234);
  *(short *)(*(int *)(iVar2 + 0x700) + 0xc) =
       *(short *)(*(int *)(iVar2 + 0x700) + 0xc) + *(char *)(param_1 + 0x207) * -200;
  *(short *)(*(int *)(iVar2 + 0x700) + 0x10) =
       *(short *)(*(int *)(iVar2 + 0x700) + 0x10) + *(char *)(param_1 + 0x207) * 200;
  if (*(short *)(*(int *)(iVar2 + 0x700) + 0xc) < 0) {
    *(char *)(param_1 + 0x207) = -*(char *)(param_1 + 0x207);
  }
  if (0x1000 < *(short *)(*(int *)(iVar2 + 0x700) + 0xc)) {
    *(char *)(param_1 + 0x207) = -*(char *)(param_1 + 0x207);
  }
  func_0x80066288(param_1,iVar2 + 0x5e0);
  func_0x80066554(param_1,iVar2 + 0x5e0);
  iVar2 = *(int *)(*(int *)(param_1 + 0x234) + 0x298);
  *(short *)(iVar2 + 0xc) = *(short *)(iVar2 + 0xc) + *(char *)(param_1 + 0x207) * -200;
  func_0x80066288();
  return;
}
