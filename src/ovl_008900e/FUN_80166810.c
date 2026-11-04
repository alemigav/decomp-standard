/* FUN_80166810
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166810  body 0x80166810..0x801668b3  size 164 B
 * body sha256 791db094e2df13ddf3180c252f1fec922251f5f213273c98c12668f610a5e3cb
 * provider record sha256 b966f17eb23344379061a5bd82a7f87f7577e0228c6932eaeb5276cdac7a2ee0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166810(int param_1)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 == 1) {
    func_0x80036d14(param_1,0,0,0);
    if (*(short *)(param_1 + 0x270) == 0) {
      return;
    }
    cVar2 = *(char *)(param_1 + 6);
  }
  else {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 4;
    func_0x80036be4(param_1,0,0,0);
    if (*(short *)(param_1 + 0x270) == 0) {
      return;
    }
    cVar2 = *(char *)(param_1 + 6);
    *(undefined2 *)(param_1 + 0x270) = 0;
    *(undefined1 *)(param_1 + 0x1e8) = 0xff;
  }
  *(char *)(param_1 + 6) = cVar2 + '\x01';
  return;
}
