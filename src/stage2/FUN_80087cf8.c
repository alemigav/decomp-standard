/* FUN_80087cf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087cf8  body 0x80087cf8..0x80087d8f  size 152 B
 * body sha256 6d72eca816c3ef20407e7681d98986d50100a02ae7fd6fc4e5aad5ad9ae48a3f
 * provider record sha256 281859fb911e03f62fc996bd0962416bf59da004c11caa1b5aec665c386e7797
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80087cf8(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  func_0x800068d0(0x8013a2f0,&DAT_80129e90,0x8013a340);
  puVar2 = &UNK_80129e94 + param_1 * 0x68;
  iVar1 = func_0x800082d0(0x8013a2f0,puVar2,param_1);
  if (iVar1 == 0) {
    func_0x80007f50(puVar2);
    func_0x80007f50(puVar2);
    func_0x80007f50(puVar2);
  }
  return;
}
