/* FUN_8016696c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016696c  body 0x8016696c..0x80166a3f  size 212 B
 * body sha256 8cebb82dfa8749b81f39dc6185fa60b7f2ec2bb7384889036d5c651509ce8507
 * provider record sha256 9263a523be6620afea7f336e1d4160494a2506436b28ba36334300de989d9384
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016696c(uint *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
    if (4 < *(byte *)((int)param_1 + 0x1e9)) {
      func_0x80036b2c(param_1 + 0xb,0,100);
    }
    iVar2 = func_0x80036d14(param_1,0xe,0,0);
    if (iVar2 != 0) {
      param_1[1] = 0x1050000;
      *param_1 = *param_1 & 0xfffffff7;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
    }
  }
  else if ((bVar1 < 2) && (bVar1 == 0)) {
    *param_1 = *param_1 | 8;
    func_0x80036be4(param_1,0xe,0,0);
    *(undefined1 *)(param_1 + 0x7a) = 0;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    if (*(short *)(param_1 + 0x9c) != 0) {
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
  }
  return;
}
