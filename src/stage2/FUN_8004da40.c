/* FUN_8004da40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004da40  body 0x8004da40..0x8004db5b  size 284 B
 * body sha256 bfca407c3c7536ca941e445c6cc27c6fe711c8930a353a95186a5f8b2298214c
 * provider record sha256 923d072c239708cb12efbf6010428fd57ca827d829655372fc3e4d12550ce6ea
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004da40(uint *param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined1 auStack_40 [32];
  
  uVar2 = param_1[0xa1];
  puVar3 = param_1 + 0x48;
  if (uVar2 != 0) {
    puVar1 = param_1 + 0x4a;
    do {
      local_56 = *(undefined2 *)((int)param_1 + 0x66);
      local_54 = 0;
      local_58 = 0;
      FUN_80040e58(&local_58,auStack_40);
      if ((*param_1 & 0x2000000) != 0) {
        FUN_80040cf4(param_1[0x1c],auStack_40);
      }
      local_58 = *(undefined2 *)(puVar1 + 2);
      local_56 = *(undefined2 *)(puVar1 + 3);
      local_54 = *(undefined2 *)((int)puVar1 + 10);
      FUN_80042824(auStack_40,&local_58,&local_50);
      *(undefined2 *)(puVar1 + 5) = local_50._2_2_;
      *(undefined2 *)((int)puVar1 + 0x16) = local_48._2_2_;
      *puVar3 = *param_2 + local_50;
      uVar2 = uVar2 - 1;
      puVar1[-1] = param_2[1] + local_4c;
      puVar3 = puVar3 + 8;
      *puVar1 = param_2[2] + local_48;
      puVar1 = puVar1 + 8;
    } while (uVar2 != 0);
  }
  return;
}
