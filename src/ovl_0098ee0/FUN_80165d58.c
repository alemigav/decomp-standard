/* FUN_80165d58
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165d58  body 0x80165d58..0x80165ec3  size 364 B
 * body sha256 2a09208778009120af5c4d0b177a050b59ed76092e9f989d20936e9d00dcbd7c
 * provider record sha256 ced86e55e87f1b1479e79f0a40c5d8cd4ae05cfc9fedaf5b273942164a7a6a7b
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165d58(int param_1)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    func_0x80077adc(0x4010001,param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0xfda8;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
  case 1:
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      *(undefined1 *)(param_1 + 6) = 2;
    }
    func_0x80032b5c(param_1,0);
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228),0x400)
    ;
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + 0x70;
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000300;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    func_0x80032b5c(param_1,0);
    cVar1 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    cVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x224),
                            *(undefined4 *)(param_1 + 0x228),0x400);
    uVar3 = *(short *)(param_1 + 0x1e0) + 0xf;
    *(ushort *)(param_1 + 0x1e0) = uVar3;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1 + cVar2;
    if (0 < (int)((uint)uVar3 << 0x10)) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined1 *)(param_1 + 0x26f) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xed;
  }
  return;
}
