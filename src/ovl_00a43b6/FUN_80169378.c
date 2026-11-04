/* FUN_80169378
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80169378  body 0x80169378..0x80169527  size 432 B
 * body sha256 9664f66f0669cf4212dd34a9578916b3084a43fb590ac51af10d3d170038c415
 * provider record sha256 b9be14986766c5f24765942b31341c87e0c6db540df2f08fb850dba2bb17ccae
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80169378(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x2bd);
  if (bVar2 == 1) {
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) = *(short *)(*(int *)(param_2 + 0x120) + 0xc) + -500
    ;
    cVar1 = *(char *)(param_1 + 699) + -1;
    *(char *)(param_1 + 699) = cVar1;
    *(short *)(param_1 + 0x2be) = *(short *)(param_1 + 0x2be) + 100;
    if (cVar1 == -1) {
      *(undefined1 *)(param_1 + 699) = 3;
      *(undefined1 *)(param_1 + 0x2bd) = 2;
    }
  }
  else if (bVar2 < 2) {
    if (bVar2 == 0) {
      *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
           *(short *)(*(int *)(param_2 + 0x120) + 0xc) + 0x400;
      if (0xc00 < *(short *)(*(int *)(param_2 + 0x120) + 0xc)) {
        *(undefined2 *)(*(int *)(param_2 + 0x120) + 0xc) = 0xc00;
        *(undefined1 *)(param_1 + 0x2bd) = 1;
        *(undefined2 *)(param_1 + 0x2be) = 0;
        *(undefined1 *)(param_1 + 699) = 3;
      }
    }
  }
  else if (bVar2 == 2) {
    *(short *)(*(int *)(param_2 + 0x120) + 0xc) = *(short *)(*(int *)(param_2 + 0x120) + 0xc) + 500;
    cVar1 = *(char *)(param_1 + 699) + -1;
    *(char *)(param_1 + 699) = cVar1;
    *(short *)(param_1 + 0x2be) = *(short *)(param_1 + 0x2be) + -100;
    if (cVar1 == -1) {
      *(undefined1 *)(param_1 + 699) = 3;
      *(undefined1 *)(param_1 + 0x2bd) = 1;
    }
  }
  bVar2 = func_0x80033604();
  DAT_801697eb = '\a' - bVar2 % 0xf;
  bVar2 = func_0x80033604();
  DAT_801697ea = '\a' - bVar2 % 0xf;
  func_0x80066288(param_1,param_2);
  return;
}
