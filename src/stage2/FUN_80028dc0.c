/* FUN_80028dc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028dc0  body 0x80028dc0..0x80028e83  size 196 B
 * body sha256 07eeaaba3ca259d6b244bfdff8364ba9ffbf46cf8fbba68b13cc680ce90d0014
 * provider record sha256 2a8f324d22233c7ebf017a99fd865282ac91b35c204419484f93f0141ccbb3f2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80028dc0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_1[5];
  iVar1 = func_0x80004cfc(puVar2[7],puVar2[8],0,&DAT_800b6b30);
  if (iVar1 == 0) {
    if (puVar2[9] != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x24;
      (**(code **)*param_1)(param_1);
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x6a;
    (**(code **)(*param_1 + 4))(param_1,0xffffffff);
    iVar1 = 2;
    *(undefined1 *)puVar2[8] = 0xff;
    *(undefined1 *)(puVar2[8] + 1) = 0xd9;
  }
  puVar2[1] = iVar1;
  puVar2[9] = 0;
  *puVar2 = puVar2[8];
  return 1;
}
