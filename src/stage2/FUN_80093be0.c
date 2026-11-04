/* FUN_80093be0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80093be0  body 0x80093be0..0x80093ddb  size 508 B
 * body sha256 7d7213d02dde707cdba8108d1fe55096a81fefc1be43418d620e3079fb51cca2
 * provider record sha256 aa4826c87ada3b85644be6f17f7a90722b31992b47836e64c7dcc4438cc14a55
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80093be0(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar6 = DAT_800c52dc;
  iVar4 = 0x19;
  iVar10 = DAT_800c52dc + 0x3b8f0;
  iVar9 = DAT_800c52dc + 0x3b910;
  iVar8 = DAT_800c52dc + 0x3b800;
  puVar7 = (undefined4 *)(DAT_800c52dc + 0x3b97c);
  iVar5 = DAT_800c52dc + 0x3b970;
  puVar2 = &DAT_8012fb04;
  do {
    iVar4 = iVar4 + -1;
    FUN_80047b04(iVar5,0);
    FUN_8004786c(iVar5,0x80,0x80,0x80);
    FUN_800478ac(iVar5,puVar2[-4],puVar2[-3]);
    FUN_800479bc(iVar5,puVar2[-2],puVar2[-1]);
    *(undefined2 *)((int)puVar7 + -2) = 0;
    *puVar7 = &DAT_8012f54c;
    puVar7 = puVar7 + 5;
    iVar5 = iVar5 + 0x14;
    puVar2 = puVar2 + -4;
  } while (iVar4 != 0);
  iVar5 = 6;
  puVar1 = (undefined2 *)(iVar6 + 0x3b80a);
  sVar3 = 0xd2;
  do {
    sVar3 = sVar3 + -0x1e;
    iVar5 = iVar5 + -1;
    FUN_80047824(iVar8,0x28,sVar3,0x28,0x1e);
    *(undefined4 **)(puVar1 + 0xd) = &DAT_8012f568;
    *puVar1 = 0x200;
    FUN_80047b3c(iVar8,0);
    FUN_8004787c(iVar8,0x80,0x80,0x80);
    puVar1 = puVar1 + 0x14;
    iVar8 = iVar8 + 0x28;
  } while (iVar5 != 0);
  iVar6 = 2;
  do {
    iVar6 = iVar6 + -1;
    FUN_80047b20(iVar10,0);
    FUN_8004789c(iVar10,0x20,0x20,0x40);
    iVar10 = iVar10 + 0x10;
  } while (iVar6 != 0);
  iVar6 = 6;
  do {
    iVar6 = iVar6 + -1;
    FUN_8004788c(iVar9,0x80,0x20,0x20);
    FUN_80047b58(iVar9,0);
    *(undefined1 *)(iVar9 + 3) = 0;
    iVar9 = iVar9 + 0x10;
  } while (iVar6 != 0);
  DAT_8012bfe8 = 7;
  DAT_8012bfea = 0xe;
  return;
}
