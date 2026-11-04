/* FUN_80079664
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079664  body 0x80079664..0x800796c3  size 96 B
 * body sha256 8feec01cf5aff5af68f8bb7e672618966bd470c69e205299cf7e749795309584
 * provider record sha256 f779edb87eebee933ed96aa06d746a895e5fe203014f08cdcdb42e0d0725d8c8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079664(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar1 + 0x1610) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x1614) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0x1618) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(iVar1 + 0x161c) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x1620) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x1624) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x1628) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x162c) = *(undefined4 *)(iVar1 + 0x24);
  FUN_8007aa2c();
  return;
}
