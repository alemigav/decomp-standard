/* FUN_80169218
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80169218  body 0x80169218..0x80169377  size 352 B
 * body sha256 8c15ea52a9fc07162e36e70628472c7ebaa028206e96929b71c807460ca184e8
 * provider record sha256 2deb7a5be8d6a2dca4cf31806298df9124a75eb5ad09879b20ad095d117b471c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80169218(int param_1,int param_2)

{
  byte bVar1;
  
  if (*(char *)(param_1 + 0x2bd) == '\0') {
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) + 0x400;
    if (0x1000 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0xc) = 0x1000;
      *(undefined1 *)(param_1 + 0x2bd) = 1;
      *(undefined2 *)(param_1 + 0x2be) = 0;
      bVar1 = func_0x80033604(param_1);
      DAT_801697eb = '\a' - bVar1 % 0xe;
      bVar1 = func_0x80033604();
      DAT_801697ea = '\a' - bVar1 % 0xe;
    }
  }
  else if (*(char *)(param_1 + 0x2bd) == '\x01') {
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
         *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2be);
    *(short *)(param_1 + 0x2be) = *(short *)(param_1 + 0x2be) + 100;
    if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < 0) {
      *(undefined2 *)(*(int *)(param_2 + 0x120) + 0xc) = 0;
      *(undefined1 *)(param_1 + 700) = 0;
      *(undefined1 *)(param_1 + 0x2bd) = 0;
      DAT_801697eb = '\0';
      DAT_801697ea = '\0';
    }
  }
  func_0x80066288(param_1,param_2);
  return;
}
