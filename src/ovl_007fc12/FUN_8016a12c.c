/* FUN_8016a12c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016a12c  body 0x8016a12c..0x8016a2eb  size 448 B
 * body sha256 68523a0ff9e203e1e351f2546140ad6d3aa134b5ba4208e2619ec1115260e6d3
 * provider record sha256 2120c2d027030c6a15a393a0d9b9d7fc4498af396ef588a824c67be8d94da62c
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016a12c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    local_18 = 0;
    local_16 = 300;
    local_14 = 0;
    func_0x80037780(0x1fa0,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x38,
                    &local_18);
    uVar2 = func_0x80033604();
    uVar4 = 0xb;
    if ((uVar2 & 1) != 0) {
      uVar4 = 0xd;
    }
    func_0x80077d18(uVar4,param_1);
    func_0x80035b84(param_1);
    cVar3 = *(char *)(param_1 + 5);
    if ((cVar3 == '\n') && ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0)) {
      FUN_80167910(param_1);
      cVar3 = *(char *)(param_1 + 5);
    }
    if ((cVar3 == '\v') && ((*(ushort *)(param_1 + 0x2b6) & 0x1000) == 0)) {
      FUN_80167abc(param_1);
    }
    cVar3 = *(char *)(param_1 + 5);
    if ((cVar3 == '\t') || (cVar3 == '\x11')) {
      if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
        FUN_80167ba4(param_1);
      }
      cVar3 = *(char *)(param_1 + 5);
    }
    if (cVar3 == '\x0e') {
      FUN_80167c88(param_1);
    }
  }
  cVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  return;
}
